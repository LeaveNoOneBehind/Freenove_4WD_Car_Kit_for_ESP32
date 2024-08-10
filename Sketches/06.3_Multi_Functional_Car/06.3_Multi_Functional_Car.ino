/**********************************************************************
  Filename    : Camera Car
  Product     : Freenove 4WD Car for ESP32
  Auther      : www.freenove.com
  Modification: 2021/03/05
**********************************************************************/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include "esp_camera.h"

#include <Freenove_4WD_Car_For_ESP32.h>

String CmdArray[8];
int paramters[8];
bool videoFlag = 0;

void WiFi_Init() {
  ssid_Router     =   "********";    // поміняйте на назву роутера
  password_Router =   "********";    // поміняйте на пароль до нього
  ssid_AP         =   "Sunshine";    // ESP32 включить точку доступу з відповідним іменем
  password_AP     =   "Sunshine";    // виставте пароль для ESP32
  frame_size      =    FRAMESIZE_CIF;// 400*296
}

WiFiServer server_Cmd(4000);
WiFiServer server_Camera(7000);

void setup() {
  Buzzer_Setup();           // ініціалізація пищалки
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  WiFi_Init();              // ініціалізація параметрів WIFI
  WiFi_Setup(1);            // запуск режиму точки доступу. Якщо хочете підключитись до роутера - поміняйте 1 на 0
  server_Cmd.begin(4000);   // запуск командного серверу
  server_Camera.begin(7000);// запуск камери

  cameraSetup();            // ініціалізація камери
  Emotion_Setup();          // ініціалізація "емоції"
  WS2812_Setup();           // ініціалізація світлодіодної стрічки
  PCA9685_Setup();          // ініціалізація контролеру для моторів
  Photosensitive_Setup();   // ініціалізація модуля для стеження за джерелом світла
  Track_Setup();            // ініціалізація модуля для стеження за лінією

  xTaskCreateUniversal(loopTask_Camera, "loopTask_Camera", 10240, NULL, 0, NULL, 0);
  xTaskCreateUniversal(loopTask_WTD, "loopTask_WTD", 10240, NULL, 0, NULL, 0);
}

void loop() {
  WiFiClient client = server_Cmd.available();                 // пошук клієнтів wifi
  if (client) {                                               // якщо клієнт підключився
    Serial.println("Cmd_Server connected to a client.");
    while (client.connected()) {                              // повторювати поки клієнт підключений
      if (client.available()) {                               // якщо є інформація для зчитування від клієнта
        String inputStringTemp = client.readStringUntil('\n');// зчитати команду по WIFI
        Serial.println(inputStringTemp);                      // вивести команду отриману по WIFI
        Get_Command(inputStringTemp);

        if (CmdArray[0] == CMD_LED_MOD) { // включити/виключити світлодіоди
          WS2812_SetMode(paramters[1]);
        }
        if (CmdArray[0] == CMD_LED) { // виставити колір і яскравість світлоіодів
          WS2812_Set_Color_1(paramters[1], paramters[2], paramters[3], paramters[4]);
        }
        if (CmdArray[0] == CMD_MATRIX_MOD) {// включити/виключити LED матрицю
          Emotion_SetMode(paramters[1]);
        }
        if (CmdArray[0] == CMD_VIDEO) {// команда для передачі відео
          videoFlag = paramters[1];
        }
        if (CmdArray[0] == CMD_BUZZER) { // команда для контролю пищалки
          Buzzer_Variable(paramters[1], paramters[2]);
        }
        if (CmdArray[0] == CMD_POWER) { // команда, яка повертає напругу батарейок
          float battery_voltage = Get_Battery_Voltage();
          client.print(CMD_POWER);
          client.print(INTERVAL_CHAR);
          client.print(battery_voltage);
          client.print(ENTER);
        }
        if (CmdArray[0] == CMD_MOTOR) {// контроль машинки по мережі
          Car_SetMode(0);
          if (paramters[1] == 0 && paramters[3] == 0) {
            Motor_Move(0, 0, 0, 0);// зупинити машинку
          }
          else {  // якщо параметр не дорівнює 0
            Motor_Move(paramters[1], paramters[1], paramters[3], paramters[3]);
          }
        }
        if (CmdArray[0] == CMD_SERVO) {// контроль сервомоторів по мережі
          if (paramters[1] == 0) {
            Servo_1_Angle(paramters[2]);
          }
          else if (paramters[1] == 1) {
            Servo_2_Angle(paramters[2]);
          }
        }
        if (CmdArray[0] == CMD_CAMERA) {// контроль сервомоторів по мережі
          Servo_1_Angle(paramters[1]);
          Servo_2_Angle(paramters[2]);
        }
        if (CmdArray[0] == CMD_LIGHT) { // команда для стеження за джерелом світла
          if (paramters[1] == 1) {
            Car_SetMode(1);
          }
          else if (paramters[1] == 0) {
            Car_SetMode(0);
          }
        }
        else if (CmdArray[0] == CMD_TRACK) { // команда для стеження за лінією
          if (paramters[1] == 1) {
            Car_SetMode(2);
          }
          else if (paramters[1] == 0) {
            Car_SetMode(0);
          }
        }
        if (CmdArray[0] == CMD_CAR_MODE) { // команда рухатись
          Car_SetMode(paramters[1]);
        }
        // очистити масиви команд і параметрів
        memset(CmdArray, 0, sizeof(CmdArray));
        memset(paramters, 0, sizeof(paramters));
      }
      Emotion_Show(emotion_task_mode);// функція для виставлення "емоції" на LED матирицю
      WS2812_Show(ws2812_task_mode);// функція для включення світлодіодів
      Car_Select(carFlag);// функція для вибору команди для ESP32
    }
    client.stop();// відключити зв'язок з клієнтом по мережі
    Serial.println("Command Client Disconnected.");
    ESP.restart();
  }
}

void loopTask_Camera(void *pvParameters) {
  while (1) {
    WiFiClient client = server_Camera.available();// пошук клієнтів
    if (client) {// якщо клієнт приєднався
      Serial.println("Camera_Server connected to a client.");
      if (client.connected()) {
        camera_fb_t * fb = NULL;
        while (client.connected()) {// повторювати поки клієнт під'єднаний
          if (videoFlag == 1) {
            fb = esp_camera_fb_get();
            if (fb != NULL) {
              uint8_t slen[4];
              slen[0] = fb->len >> 0;
              slen[1] = fb->len >> 8;
              slen[2] = fb->len >> 16;
              slen[3] = fb->len >> 24;
              client.write(slen, 4);
              client.write(fb->buf, fb->len);
              Serial.println("Camera send");
              esp_camera_fb_return(fb);
            }
          }
        }
        // відключити зв'язок
        client.stop();
        Serial.println("Camera Client Disconnected.");
        ESP.restart();
      }
    }
  }
}

void Get_Command(String inputStringTemp)
{
  int string_length = inputStringTemp.length();
  for (int i = 0; i < 8; i++) {// розпарсити команду, отриману по WIFI 
    int index = inputStringTemp.indexOf(INTERVAL_CHAR);
    if (index < 0) {
      if (string_length > 0) {
        CmdArray[i] = inputStringTemp;         // отримати команду
        paramters[i] = inputStringTemp.toInt();// отрмати параметри
      }
      break;
    }
    else {
      string_length -= index;                                // кількість "слів", що залишилась
      CmdArray[i] = inputStringTemp.substring(0, index);     // отрмати команду
      paramters[i] = CmdArray[i].toInt();                    // отрмати параметри
      inputStringTemp = inputStringTemp.substring(index + 1);// оновити стрічку
    }
  }
}
