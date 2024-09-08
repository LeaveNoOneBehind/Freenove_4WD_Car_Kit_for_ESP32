#ifndef FREENOVE_PHOTOSENSITIVE_H
#define FREENOVE_PHOTOSENSITIVE_H

#define PHOTOSENSITIVE_PIN   33

extern int light_init_value;            //Set the car's initial environment ADC value


void Photosensitive_Setup(void);           //Photosensitive initialization
int Get_Photosensitive(void);              //Gets the photosensitive resistance value

#endif //FREENOVE_PHOTOSENSITIVE_H
