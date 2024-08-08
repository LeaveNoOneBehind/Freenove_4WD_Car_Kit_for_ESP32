#include "Freenove_WiFi.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

char* ssid_Router     =   "********";    //Modify according to your router name
char* password_Router =   "********";    //Modify according to your router password
char* ssid_AP         =   "Sunshine";    //ESP32 turns on an AP and calls it Sunshine
char* password_AP     =   "Sunshine";    //Set your AP password for ESP32 to Sunshine
bool WiFi_MODE = 1;

IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

void WiFi_Setup(bool WiFi_Mode)
{
  if (WiFi_Mode == 0)
  {
    WiFi_MODE = 0;
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid_Router, password_Router);
    WiFi.setSleep(false);
    // WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);

    Serial.print("\nWaiting for WiFi... ");
    while (WiFi.isConnected() != true) {
      Serial.print(".");
      delay(500);
    }
    IPAddress local_ip = WiFi.localIP();
    Serial.println("");
    Serial.println("\nWiFi connected");
    Serial.print("Use your phone to connect to WiFi: ");
    Serial.println(ssid_Router);
    Serial.print("\nThe password for WiFi is: ");
    Serial.println(password_Router);
    Serial.print("\nThen you can enter: '");
    Serial.print(local_ip);
    Serial.println("' to connect the car in Freenove app.");
    Buzzer_Alarm(1);
    delay(100);
    Buzzer_Alarm(0);
  }
  else
  {
    WiFi_MODE = 1;
    WiFi.disconnect(true);
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(ssid_AP, password_AP);

    Serial.print("\nUse your phone to connect to WiFi: ");
    Serial.println(ssid_AP);
    Serial.print("\nThe password for WiFi is: ");
    Serial.println(password_AP);
    Serial.print("\nThen you can enter: '");
    Serial.print(local_IP);
    Serial.println("' to connect the car in Freenove app.");
    Buzzer_Alarm(1);
    delay(100);
    Buzzer_Alarm(0);
  }
}

int wtdFlag = 0;
void loopTask_WTD(void *pvParameters) {
  while (1)
  {
    if (WiFi_MODE == 0)
    {
      if ((WiFi.isConnected() == 0) && wtdFlag == 0)
      {
        delay(100);
      }
      else if ((WiFi.isConnected() != 0) && wtdFlag == 0)
      {
        wtdFlag = 1;
        delay(100);
      }
      else if ((WiFi.isConnected() == 0) && wtdFlag == 1)
      {
        wtdFlag = 0;
        ESP.restart();
      }
    }
    else
    {
      if ((WiFi.softAPgetStationNum() == 0) && wtdFlag == 0)
      {
        delay(100);
      }
      else if ((WiFi.softAPgetStationNum() != 0) && wtdFlag == 0)
      {
        wtdFlag = 1;
        delay(100);
      }
      else if ((WiFi.softAPgetStationNum() == 0) && wtdFlag == 1)
      {
        wtdFlag = 0;
        ESP.restart();
      }
    }
  }
}