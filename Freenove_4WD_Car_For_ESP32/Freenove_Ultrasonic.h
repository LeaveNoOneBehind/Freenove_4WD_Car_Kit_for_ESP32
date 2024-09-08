#ifndef FREENOVE_ULTRASONIC_H
#define FREENOVE_ULTRASONIC_H

#define PIN_SONIC_TRIG    12            //define Trig pin
#define PIN_SONIC_ECHO    15            //define Echo pin
#define MAX_DISTANCE      300           //cm
#define SONIC_TIMEOUT (MAX_DISTANCE*60) // calculate timeout
#define SOUND_VELOCITY    340           //soundVelocity: 340m/s

void Ultrasonic_Setup(void);//Ultrasonic initialization
float Get_Sonar(void);//Obtain ultrasonic distance data


#endif //FREENOVE_ULTRASONIC_H
