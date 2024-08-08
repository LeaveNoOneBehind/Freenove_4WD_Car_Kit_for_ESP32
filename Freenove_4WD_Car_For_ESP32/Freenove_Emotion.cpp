#include <Arduino.h>
#include "Freenove_Emotion.h"
#include "Freenove_VK16K33_Lib_For_ESP32.h"
#include "Emotions.h"

Freenove_ESP32_VK16K33 matrix = Freenove_ESP32_VK16K33();
int time_before=0;      //Record each non-blocking time
int time_count=0;       //Record the number of non-blocking times
int time_flag=0;        //Record the blink time


//clear all
void clearEmtions(void)
{
  emotion_count = 0;
  int count = sizeof(clearEmotion) / sizeof(clearEmotion[0]);
  for (int i = 0; i < count; i++)
  {
    matrix.showStaticArray(clearEmotion[i], clearEmotion[i]);
  }
}


//Initialize
void Emotion_Setup()
{
  matrix.init(EMOTION_ADDRESS, EMOTION_SDA, EMOTION_SCL);
  time_before=millis();
}

//Turn the eyes-1
void eyesRotate(int delay_ms)
{
  int count = sizeof(eyeRotate1) / sizeof(eyeRotate1[0]);
  if(millis()-time_before>=delay_ms)
  {
    matrix.showStaticArray(eyeRotate1[time_count], eyeRotate2[time_count]);
    time_before=millis();
    time_count++;
    if(time_count>=count)
      time_count=0;
  }
}

//Wink the eyes-2
void eyesBlink(int delay_ms)
{
  int count = sizeof(eyeBlink) / sizeof(eyeBlink[0]);
  if(millis()-time_before>=delay_ms)
  {
    time_before=millis();
    time_count++;
    if(time_count>=25)
    {
      time_count=0;
      time_flag=1;
    }
    if(time_flag==0)
      matrix.showStaticArray(eyeBlink[0], eyeBlink[0]);
    else if(time_flag==1)
    {
      matrix.showStaticArray(eyeBlink[time_count], eyeBlink[time_count]);
      if(time_count>=(count-1))
      {
        time_flag=0;
        time_count=0;
      }
    }
  }
}

//Smile-3
void eyesSmile(int delay_ms)
{
  int count = sizeof(eyeSmile) / sizeof(eyeSmile[0]);
  if(millis()-time_before>=delay_ms)
  {
    matrix.showStaticArray(eyeSmile[time_count], eyeSmile[time_count]);
    time_before=millis();
    time_count++;
    if(time_count>=count)
      time_count=0;
  }
}

//Cry-4
void eyesCry(int delay_ms)
{
  int count = sizeof(eyeCry1) / sizeof(eyeCry1[0]);
  if(millis()-time_before>=delay_ms)
  {
    matrix.showStaticArray(eyeCry1[time_count], eyeCry2[time_count]);
    time_before=millis();
    time_count++;
    if(time_count>=count)
      time_count=0;
  }
}

//Wink the eyes-5
void eyesBlink1(int delay_ms)
{
  int count = sizeof(eyeBlink1) / sizeof(eyeBlink1[0]);
  if(millis()-time_before>=delay_ms)
  {
    time_before=millis();
    time_count++;
    if(time_count>=15)
    {
      time_count=0;
      time_flag=1;
    }
    if(time_flag==0)
      matrix.showStaticArray(eyeBlink1[0], eyeBlink1[0]);
    else if(time_flag==1)
    {
      matrix.showStaticArray(eyeBlink1[time_count], eyeBlink1[time_count]);
      if(time_count>=(count-1))
      {
        time_flag=0;
        time_count=0;
      }
    }
  }
}

//show_arrow-6
void showArrow(int arrow_direction,int delay_ms)
{
  if (arrow_direction == 1)
  {
    if(millis()-time_before>=delay_ms)
    {
      matrix.showLedMatrix(arrow_up, 4, time_count-8);
      time_before=millis();
      time_count++;
      if(time_count>16)
        time_count=0;
    }
  }
  else if (arrow_direction == 2)
  {
    if(millis()-time_before>=delay_ms)
    {
      matrix.showLedMatrix(arrow_dowm, 4, 8-time_count);
      time_before=millis();
      time_count++;
      if(time_count>16)
        time_count=0;
    }
  }
  else if (arrow_direction == 3)
  {
    if(millis()-time_before>=delay_ms)
    {
      matrix.showLedMatrix(arrow_left, 8-time_count, 0);
      time_before=millis();
      time_count++;
      if(time_count>8)
        time_count=0;
    }
  }
  else if (arrow_direction == 4)
  {
    if(millis()-time_before>=delay_ms)
    {
      matrix.showLedMatrix(arrow_right, time_count, 0);
      time_before=millis();
      time_count++;
      if(time_count>8)
        time_count=0;
    }
  }
  else
    matrix.clear();
}

//wheel-7
void wheel(int mode, int delay_ms)
{
  if (mode == 1)
  {
    int count = sizeof(wheel_left) / sizeof(wheel_left[0]);
    if(millis()-time_before>=delay_ms)
    {
      matrix.showStaticArray(wheel_left[time_count], wheel_left[time_count]);
      time_before=millis();
      time_count++;
      if(time_count>=count)
        time_count=0;
    }
  }
  else if (mode == 2)
  {
    int count = sizeof(wheel_right) / sizeof(wheel_right[0]);
    if(millis()-time_before>=delay_ms)
    {
      matrix.showStaticArray(wheel_right[time_count], wheel_right[time_count]);
      time_before=millis();
      time_count++;
      if(time_count>=count)
        time_count=0;
    }
  }
  else
    matrix.clear();
}

//Car-8
void carMove(int mode,int delay_ms)
{
  if (mode == 1)
  {
    if(millis()-time_before>=delay_ms)
    {
      matrix.showLedMatrix(car_left, 8-time_count, 0);
      time_before=millis();
      time_count++;
      if(time_count>=8)
        time_count=0;
    }
  }
  else if (mode == 2)
  {
    if(millis()-time_before>=delay_ms)
    {
      matrix.showLedMatrix(car_right, time_count, 0);
      time_before=millis();
      time_count++;
      if(time_count>=8)
        time_count=0;
    }
  }
  else
    matrix.clear();
}

//expressing love-9
void expressingLove(int delay_ms)
{
    int count = sizeof(I_love_you) / sizeof(I_love_you[0]);
    if(millis()-time_before>=delay_ms)
    {
      matrix.showStaticArray(I_love_you[0], I_love_you[1]);
      time_before=millis();
      time_count++;
      if(time_count>=count)
        time_count=0;
    }
}

//save water-10
void saveWater(int delay_ms)
{
    int count = sizeof(save_water_left) / sizeof(save_water_left[0]);
    if(millis()-time_before>=delay_ms)
    {
      matrix.showStaticArray(save_water_left[time_count], save_water_right[time_count]);
      time_before=millis();
      time_count++;
      if(time_count>=count)
        time_count=0;
    }
}

//show static emotion
void staticEmtions(int emotion)
{
  int count = sizeof(static_emotion_left) / sizeof(static_emotion_left[0]);
  emotion = constrain(emotion, 0, count-1);
  matrix.showStaticArray(static_emotion_left[emotion], static_emotion_right[emotion]);
}


int emotion_task_mode = 0;
//Emotion show
void Emotion_Show(int mode)
{
  if (mode == 0)
    clearEmtions();
  else if (mode == 1)
    eyesRotate(150);
  else if (mode == 2)
    eyesCry(200);
  else if (mode == 3)
    eyesSmile(200);
  else if (mode == 4)
    wheel(2, 100);
  else if (mode == 5)
    wheel(1, 100);
  else if (mode == 6)
    eyesBlink(100);
}

//Emotion set mode
void Emotion_SetMode(int mode)
{
  if (mode <= 6)
    emotion_task_mode = mode;
  else if (mode >= 7)
  {
    emotion_task_mode = 7;
    int emotion_flag = millis() % 22;
    Serial.println("emotion_flag:"+String(emotion_flag));
    staticEmtions(emotion_flag);
  }
}



