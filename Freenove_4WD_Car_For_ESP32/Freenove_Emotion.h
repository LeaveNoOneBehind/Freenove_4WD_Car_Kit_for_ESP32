#ifndef FREENOVE_EMOTION_H
#define FREENOVE_EMOTION_H

#define EMOTION_ADDRESS 0x71
#define EMOTION_SDA     13
#define EMOTION_SCL     14

void Emotion_Setup();                            //Initialize
void eyesRotate(int delay_ms);                   //Turn the eyes-1
void eyesBlink(int delay_ms);                    //Wink the eyes-2
void eyesSmile(int delay_ms);                    //Smile-3
void eyesCry(int delay_ms);                      //Cry-4
void eyesBlink1(int delay_ms);                   //Wink the eyes-5
void showArrow(int arrow_direction,int delay_ms);//Arrow-6
void wheel(int mode,int delay_ms);               //wheel-7
void carMove(int mode,int delay_ms);             //car-8
void expressingLove(void);                       //expressing love-9
void saveWater(int delay_ms);                    //save water-10


void Emotion_Show(int mode);       //Display:0-Display off,1-Turn the eyes,2-blink eyes,3-smile,4-cry,5-left-wheel,6-right-wheel
void Emotion_SetMode(int mode);    //set the emotion show mode
void staticEmtions(int emotion);   //show static emotion

#endif //FREENOVE_EMOTION_H
