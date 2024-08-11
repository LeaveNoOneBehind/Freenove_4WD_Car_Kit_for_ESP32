/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : use servo.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include <Freenove_4WD_Car_For_ESP32.h>

void setup()
{
  PCA9685_Setup();    // Ініціалізація серводвигуна
}

void loop()
{
  Servo_1_Angle(90);  // Встановити значення кута сервоприводу 1 на 90°
  Servo_2_Angle(90);  // Встановити значення кута сервоприводу 2 на 90°
  delay(1000);
}
