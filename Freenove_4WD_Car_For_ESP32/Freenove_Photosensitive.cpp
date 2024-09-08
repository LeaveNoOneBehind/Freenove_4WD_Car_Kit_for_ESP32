#include <Arduino.h>
#include "Freenove_Photosensitive.h"

int light_init_value = 0;   //Set the car's initial environment ADC value


void Photosensitive_Setup(void)
{
    pinMode(PHOTOSENSITIVE_PIN, INPUT);
    light_init_value = Get_Photosensitive();   //Set the car's initial environment ADC value

}

//Gets the photosensitive resistance value
int Get_Photosensitive(void)
{
    int photosensitiveADC = analogRead(PHOTOSENSITIVE_PIN);
    return photosensitiveADC;
}
