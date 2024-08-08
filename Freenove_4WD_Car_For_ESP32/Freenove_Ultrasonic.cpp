#include <Arduino.h>
#include "Freenove_Ultrasonic.h"

void Ultrasonic_Setup(void)
{
    pinMode(PIN_SONIC_TRIG, OUTPUT);// set trigPin to output mode
    pinMode(PIN_SONIC_ECHO, INPUT); // set echoPin to input mode
}

//Obtain ultrasonic distance data
float Get_Sonar(void)
{
    unsigned long pingTime;
    float distance;
    digitalWrite(PIN_SONIC_TRIG, HIGH); // make trigPin output high level lasting for 10μs to triger HC_SR04,
    delayMicroseconds(10);
    digitalWrite(PIN_SONIC_TRIG, LOW);
    pingTime = pulseIn(PIN_SONIC_ECHO, HIGH, SONIC_TIMEOUT); // Wait HC-SR04 returning to the high level and measure out this waitting time
    if (pingTime != 0)
        distance = (float)pingTime * SOUND_VELOCITY / 2 / 10000; // calculate the distance according to the time
    else
        distance = MAX_DISTANCE;
    return distance; // return the distance value
}
