/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Ultrasonic ranging and servo.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include <Arduino.h>
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  Serial.begin(115200); // Підключити Serial і встановити швидкість передачі на 115200
  Ultrasonic_Setup();   // Ініціалізація ультразвукового модуля
  PCA9685_Setup();      // Ініціалізація серводвигуна
  Servo_1_Angle(90);    // Встановити початкове значення серводвигуна 1 на 90 градусів
  Servo_2_Angle(90);    // Встановити початкове значення серводвигуна 2 на 90 градусів
  delay(500);           // Затримка, щоб дочекатися, поки серводвигун займе потрібне положення
}

void loop() {
  Servo_1_Angle(150);   // Повернути серводвигун 1 на 150 градусів
  Serial.print("Distance: " + String(Get_Sonar()) + "\n"); // Вивести на екран відстань, виміряну ультразвуковим датчиком
  delay(500);

  Servo_1_Angle(90);    // Повернути серводвигун 1 на 90 градусів
  Serial.print("Distance: " + String(Get_Sonar()) + "\n"); // Вивести на екран відстань, виміряну ультразвуковим датчиком
  delay(500);

  Servo_1_Angle(30);    // Повернути серводвигун 1 на 30 градусів
  Serial.print("Distance: " + String(Get_Sonar()) + "\n"); // Вивести на екран відстань, виміряну ультразвуковим датчиком
  delay(500);

  Servo_1_Angle(90);    // Повернути серводвигун 1 на 90 градусів
  Serial.print("Distance: " + String(Get_Sonar()) + "\n"); // Вивести на екран відстань, виміряну ультразвуковим датчиком
  delay(500);
}
