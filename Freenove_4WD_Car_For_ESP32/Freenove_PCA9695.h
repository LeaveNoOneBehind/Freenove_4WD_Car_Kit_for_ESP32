#ifndef FREENOVE_PCA9695_H
#define FREENOVE_PCA9695_H

#include <Arduino.h>
#include <PCA9685.h>

#define MOTOR_1_DIRECTION     -1 //If the direction is reversed, change 1 to -1
#define MOTOR_2_DIRECTION     -1 //If the direction is reversed, change 1 to -1
#define MOTOR_3_DIRECTION     -1 //If the direction is reversed, change 1 to -1
#define MOTOR_4_DIRECTION     -1 //If the direction is reversed, change 1 to -1

#define PCA9685_SDA 13  //Define SDA pins
#define PCA9685_SCL 14  //Define SCL pins
#ifndef PCA9685_ADDRESS
#define PCA9685_ADDRESS 0x5F
#endif
#define SERVO_FREQUENCY 50       //Define the operating frequency of servo
#define PCA9685_CHANNEL_0 0      //Define PCA9685 channel to control servo 1
#define PCA9685_CHANNEL_1 1      //Define the PCA9685 channel to control servo 2
#define SERVO_MIDDLE_POINT 1500  //Define the middle position of the servo
#define MOTOR_SPEED_MIN -4095    //Define a minimum speed limit for wheels
#define MOTOR_SPEED_MAX 4095     //Define a maximum speed limit for wheels
#define PIN_MOTOR_M1_IN1 15      //Define the positive pole of M1
#define PIN_MOTOR_M1_IN2 14      //Define the negative pole of M1
#define PIN_MOTOR_M2_IN1 9       //Define the positive pole of M2
#define PIN_MOTOR_M2_IN2 8       //Define the negative pole of M2
#define PIN_MOTOR_M3_IN1 12      //Define the positive pole of M3
#define PIN_MOTOR_M3_IN2 13      //Define the negative pole of M3
#define PIN_MOTOR_M4_IN1 10      //Define the positive pole of M4
#define PIN_MOTOR_M4_IN2 11      //Define the negative pole of M4


void PCA9685_Setup(void);              //servo initialization
void Servo_1_Angle(float angle);       //Set the rotation parameters of servo 1, and the parameters are 0-180 degrees
void Servo_2_Angle(float angle);       //Set the rotation parameters of servo 2, and the parameters are 0-180 degrees
void Servo_Sweep(int servo_id, int angle_start, int angle_end);//Servo sweep function;
void Motor_Move(int m1_speed, int m2_speed, int m3_speed, int m4_speed);//A function to control the car motor


#endif //FREENOVE_PCA9695_H
