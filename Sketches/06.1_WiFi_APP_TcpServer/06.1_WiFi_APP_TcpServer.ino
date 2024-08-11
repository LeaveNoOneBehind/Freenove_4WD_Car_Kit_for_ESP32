/**********************************************************************
  Filename    : Camera Tcp Server
  Product     : Freenove 4WD Car for ESP32
  Auther      : www.freenove.com
  Modification: 2021/12/02
**********************************************************************/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char* ssid_Router     =   "********";   // Змініть відповідно до назви вашого роутера
const char* password_Router =   "********";   // Змініть відповідно до пароля вашого роутера
const char* ssid_AP         =   "Sunshine";   // ESP32 запускає точку доступу з іменем Sunshine
const char* password_AP     =   "Sunshine";   // Встановити пароль для точки доступу ESP32 на Sunshine
WiFiServer server_Cmd(4000);
WiFiServer server_Camera(7000);

void setup() {
  Serial.begin(115200);
  Serial.println();
  WiFi.softAP(ssid_AP, password_AP); // Увімкнути функцію AP ESP32
  server_Camera.begin(7000);        // Увімкнути сервер камери
  server_Cmd.begin(4000);           // Увімкнути сервер команд
  server_Camera.setNoDelay(true);   // Відключити затримки при передачі та отриманні даних для камери
  server_Cmd.setNoDelay(true);      // Відключити затримки при передачі та отриманні даних для команд
  //////////////////////////////////////////////////////////
  WiFi.disconnect(true);
  WiFi.begin(ssid_Router, password_Router); // Надіслати запит на підключення до роутера
  Serial.print("Connecting ");
  Serial.print(ssid_Router);
  int timeout = 0;
  while (WiFi.isConnected() != true) { // Якщо підключення не вдається, почекати півсекунди для повторного запиту
    delay(500);
    Serial.print(".");
    timeout++;
    // WiFi.begin(ssid_Router, password_Router);
    if (timeout == 20)
      break;
  }
  //////////////////////////////////////////////////////////
  Serial.print("\nCamera Ready! Use '");
  Serial.print(WiFi.softAPIP());
  Serial.print(" or ");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect in Freenove app.");
}

void loop() {
  WiFiClient client = server_Cmd.available(); // Чекати на вхідні з'єднання
  if (client)                                // Якщо з'єднання встановлено,
  {
    Serial.println("Command Server connected to a client.");
    while (client.connected()) { // Виконувати поки клієнт підключений
      if (client.available()) { //Якщо надійшла інформація від клієнта,
        String dataBuffer = client.readStringUntil('\n') + String("\n"); // Читати дані
        Serial.print(dataBuffer); // Вивести їх у Serial monitor
      }
    }
    client.stop(); // Закрити з'єднання
    Serial.println("Command Client Disconnected.");
  }
}

