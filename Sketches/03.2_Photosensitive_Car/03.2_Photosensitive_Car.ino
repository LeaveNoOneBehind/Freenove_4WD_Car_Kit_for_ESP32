/**********************************************************************
  Filename    : Photosensitive_Car.ino
  Product     : Freenove 4WD Car for ESP32
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include <Arduino.h>
#include <Freenove_4WD_Car_For_ESP32.h>

int photosensitive_sensitivity = 100;// виставте чутливість фоторезистора   
int photosensitive_init_value = 0;   // початкове значення освітленості

void setup()
{
  Emotion_Setup();
  Buzzer_Setup();
  Photosensitive_Setup();    // ініціалізація фоторезистора
  PCA9685_Setup();           // ініціалізація контролера моторів
  photosensitive_init_value = Get_Photosensitive();
  //Buzzer_Alert(1,1);       // пищалка буде пищати, сповіщаючи про те, що можна починати "грати" з машинкою
}

void loop()
{
  // є джерело світла по ліву сторону від машини
  if (Get_Photosensitive() < (photosensitive_init_value - photosensitive_sensitivity))
  {
    wheel(2,100);
    Motor_Move(-2000, -2000, 2000, 2000);
  }
  // є джерело світла по праву сторону від машини
  else if (Get_Photosensitive() > (photosensitive_init_value + photosensitive_sensitivity))
  {
    wheel(1,100);
    Motor_Move(2000, 2000, -2000, -2000);
  }
  // джерело світла прямо світить на машинку
  else
  {
    eyesBlink(100);
    Motor_Move(0, 0, 0, 0);
  } 
}
