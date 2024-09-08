#ifndef FREENOVE_WIFI_H
#define FREENOVE_WIFI_H

#include <Arduino.h>

#define ENTER               '\n'                  //ENTER
#define INTERVAL_CHAR       '#'                   //INTERVAL CHAR
#define CMD_MOTOR           "CMD_MOTOR"           //Motor control command
#define CMD_POWER           "CMD_POWER"           //Power control command
#define CMD_BUZZER          "CMD_BUZZER"          //BUZZER control command
#define CMD_SERVO           "CMD_SERVO"           //SERVO control command
#define CMD_CAMERA          "CMD_CAMERA"          //SERVO control command

#define CMD_LED_MOD         "CMD_LED_MOD"         //WS2812 control command
#define CMD_LED             "CMD_LED"             //WS2812 color command
#define CMD_MATRIX_MOD      "CMD_MATRIX_MOD"      //LED MATRIX control command
#define CMD_VIDEO           "CMD_VIDEO"           //VIDEO control command
#define CMD_LIGHT           "CMD_LIGHT"           //LIGHT Car control command
#define CMD_TRACK           "CMD_TRACK"           //TRACK Car control command
#define CMD_CAR_MODE        "CMD_CAR_MODE"        //Car control command

extern char* ssid_Router             ;    //Modify according to your router name
extern char* password_Router         ;    //Modify according to your router password
extern char* ssid_AP                 ;    //ESP32 turns on an AP and calls it Sunshine
extern char* password_AP             ;    //Set your AP password for ESP32 to Sunshine
void WiFi_Setup(bool WiFi_Mode)      ;    //Initialize WiFi function
void loopTask_WTD(void *pvParameters);

#endif //FREENOVE_WIFI_H
