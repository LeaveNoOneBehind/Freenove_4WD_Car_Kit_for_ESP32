#include <Arduino.h>
#include "Freenove_Photosensitive.h"

void Photosensitive_Setup(void)
{
    pinMode(PHOTOSENSITIVE_PIN, INPUT);
}

//Gets the photosensitive resistance value
int Get_Photosensitive(void)
{
    int photosensitiveADC = analogRead(PHOTOSENSITIVE_PIN);
    return photosensitiveADC;
}