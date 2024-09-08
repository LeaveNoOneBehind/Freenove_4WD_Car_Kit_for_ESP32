#ifndef FREENOVE_BUZZER_H
#define FREENOVE_BUZZER_H

//Buzzer pin definition
#define PIN_BUZZER 2                    //Define the pins for the ESP32 control buzzer
#define BUZZER_CHN 0                    //Define the PWM channel for ESP32
#define BUZZER_FREQUENCY 2000           //Define the resonant frequency of the buzzer

void Buzzer_Setup(void);                //Buzzer initialization
void Buzzer_Alert(int beat, int rebeat);//Buzzer alarm function
void Buzzer_Alarm(bool enable);          //Buzzer alarm function
void Buzzer_Variable(bool enable, int frequency);//Buzzer variable frequency(Parameter 1, enabling signal, parameter 2, frequency value)


#endif //FREENOVE_BUZZER_H
