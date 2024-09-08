/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : use servo.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include <Freenove_4WD_Car_For_ESP32.h>

void setup()
{
  PCA9685_Setup();       // Ініціалізує мікросхему, яка керує мотором
  Servo_1_Angle(90);     // Встановити кут серводвигуна 1
  Servo_2_Angle(90);     // Встановити кут серводвигуна 2
  delay(1000);
}

void loop()
{
  // Траєкторія руху серводвигуна 1; 90°- 0°- 180°- 90°
  Servo_Sweep(1, 90, 0);
  Servo_Sweep(1, 0, 180);
  Servo_Sweep(1, 180, 90);

  // Траєкторія руху серводвигуна 2; 90°- 150°- 90°
  Servo_Sweep(2, 90, 150);
  Servo_Sweep(2, 150, 90);
}
