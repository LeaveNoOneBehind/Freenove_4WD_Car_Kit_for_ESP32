#ifndef FREENOVE_TRACK_H
#define FREENOVE_TRACK_H

#define PCF8574_ADDRESS 0x20     //Tracking module IIC address
#define PCF8574_SDA     13       //Define the SDA pin number
#define PCF8574_SCL     14       //Define the SCL pin number

extern unsigned char sensorValue[4];
void Track_Setup(void);               //Trace module initialization
void Track_Read(void);                //Tracking module reading


#endif //FREENOVE_TRACK_H
