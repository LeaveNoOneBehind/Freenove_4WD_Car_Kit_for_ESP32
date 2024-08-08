#include <Arduino.h>
#include "Freenove_Track.h"

unsigned char sensorValue[4] = {0};
PCF8574 TRACK_SENSOR(PCF8574_ADDRESS);

//Trace module initialization
void Track_Setup(void)
{
    Wire.begin(PCF8574_SDA, PCF8574_SCL);
    TRACK_SENSOR.begin();
}

//Tracking module reading
void Track_Read(void)
{
    sensorValue[3] = (TRACK_SENSOR.read8() & 0x07);//composite value
    sensorValue[0] = (sensorValue[3] & 0x01) >> 0; //On the left - 1
    sensorValue[1] = (sensorValue[3] & 0x02) >> 1; //In the middle - 2
    sensorValue[2] = (sensorValue[3] & 0x04) >> 2; //On the right - 4
}
