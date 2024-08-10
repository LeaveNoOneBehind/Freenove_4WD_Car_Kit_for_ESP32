#include "Freenove_4WD_Car_For_ESP32.h"

#define SPEED_LV4       (4000)
#define SPEED_LV3       (3000)
#define SPEED_LV2       (2500)
#define SPEED_LV1       (1500)

//Light Car
void Light_Car(int mode)
{
  if (mode == 1)
  {
    if (Get_Photosensitive() < (light_init_value - 100))
    {
      Motor_Move(2000, 2000, -2000, -2000);
      Emotion_SetMode(4);
    }
    else if (Get_Photosensitive() > (light_init_value + 100))
    {
      Motor_Move(-2000, -2000, 2000, 2000);
      Emotion_SetMode(5);
    }
    else
    {
      Motor_Move(0, 0, 0, 0);
      Emotion_SetMode(1);
    }
  }
}

//Track Car
void Track_Car(int mode)
{
  if (mode == 1)
  {
    Track_Read();
    switch (sensorValue[3])
    {
      case 2:   //010
      case 5:   //101
        Emotion_SetMode(3);
        Motor_Move(-SPEED_LV1, -SPEED_LV1, -SPEED_LV1, -SPEED_LV1);    //Move Forward
        break;
      case 0:   //000
      case 7:   //111
        Emotion_SetMode(6);
        Motor_Move(0, 0, 0, 0);                                    //Stop
        break;
      case 1:   //001
      case 3:   //011
        Emotion_SetMode(4);
        Motor_Move(SPEED_LV3, SPEED_LV3, -SPEED_LV4, -SPEED_LV4);  //Turn Left
        break;
      case 4:   //100
      case 6:   //110
        Emotion_SetMode(5);
        Motor_Move(-SPEED_LV4, -SPEED_LV4 , SPEED_LV3, SPEED_LV3);//Turn Right
        break;

      default:
        break;
    }
  }
}


//////////////////////Car drive area////////////////////////////////////////
int carFlag = 0;
//set car mode
void Car_SetMode(int mode)
{
  carFlag = mode;
}

//select it to run car
void Car_Select(int mode)
{
  if (mode == 1)
  {
    Light_Car(1);
    Track_Car(0);
  }
  else if (mode == 2)
  {
    Light_Car(0);
    Track_Car(1);
  }
  else
  {
    Light_Car(0);
    Track_Car(0);
  }
}
