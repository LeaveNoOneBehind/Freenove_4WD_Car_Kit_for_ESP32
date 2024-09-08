/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Ultrasonic Car.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include <Arduino.h>
#include <Freenove_4WD_Car_For_ESP32.h>

#define OBSTACLE_DISTANCE      40
#define OBSTACLE_DISTANCE_LOW  20
int distance[4];     // Буфер для зберігання даних ультразвукового датчика

void setup() {
  Ultrasonic_Setup(); // Ініціалізація ультразвукового модуля
  PCA9685_Setup();    // Ініціалізація мікросхеми PCA9685
}

void loop()
{
  get_distance(1); // Налаштування для отримання даних з кількох точок навколо машинки
  if (distance[1] > OBSTACLE_DISTANCE) // Перед машинкою немає перешкод в межах 40 см
  {
    if (distance[0] >= distance[2] && distance[2] < OBSTACLE_DISTANCE_LOW)    // Перешкода з правого боку
      Motor_Move(-1000, -1000, 2000, 2000);                                   
    else if (distance[0] < distance[2] && distance[0] < OBSTACLE_DISTANCE_LOW) // Перешкода з лівого боку
      Motor_Move(2000, 2000, -1000, -1000);                                  
    else                                                                      // Перешкод немає навколо
      Motor_Move(1000, 1000, 1000, 1000);                                                                         
    delay(20);
  }

  else if (distance[1] < OBSTACLE_DISTANCE)  // Перед машинкою є перешкода
  {
    Motor_Move(0, 0, 0, 0);                  // Зупинити машинку для повторного визначення відстані
    get_distance(2);
    if (distance[1] < OBSTACLE_DISTANCE_LOW) // Машинка надто близько до перешкоди
      Motor_Move(-1000, -1000, -1000, -1000);
    else if (distance[0] < distance[2])      // Перешкода перед машинкою і зліва від неї
      Motor_Move(2000, 2000, -2000, -2000);
    else if (distance[0] > distance[2])      // Перешкода перед машинкою і справа від неї
      Motor_Move(-2000, -2000, 2000, 2000);
    delay(200);
  }
}

// Отримати значення відстані для різних кутів
void get_distance(int car_mode)
{
  int add_angle = 30;
  if (car_mode == 1)
    add_angle = 0;
  else
    add_angle = 30;
    
  Servo_2_Angle(90);  
  Servo_1_Angle(120 + add_angle);
  delay(100);
  distance[0] = Get_Sonar(); // Отримати відстань до перешкоди ліворуч від машинки

  Servo_1_Angle(90);
  delay(100);
  distance[1] = Get_Sonar(); // Отримати відстань до перешкоди прямо перед машинкою

  Servo_1_Angle(60 - add_angle);
  delay(100);
  distance[2] = Get_Sonar(); // Отримати відстань до перешкоди праворуч від машинки

  Servo_1_Angle(90);
  delay(100);
  distance[1] = Get_Sonar(); // Отримати відстань до перешкоди прямо перед машинкою
}
