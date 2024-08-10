#ifndef FREENOVE_4WD_CAR_FOR_ESP32_H
#define FREENOVE_4WD_CAR_FOR_ESP32_H

#include "Freenove_Battery.h"
#include "Freenove_Buzzer.h"
#include "Freenove_Camera.h"
#include "Freenove_Emotion.h"
#include "Freenove_LED.h"
#include "Freenove_PCA9695.h"
#include "Freenove_Photosensitive.h"
#include "Freenove_Track.h"
#include "Freenove_Ultrasonic.h"
#include "Freenove_WiFi.h"

#endif //FREENOVE_4WD_CAR_FOR_ESP32_H

void Light_Car(int mode);
void Track_Car(int mode);

extern int carFlag;
void Car_SetMode(int mode);
void Car_Select(int mode);
