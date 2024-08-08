#include <Arduino.h>
#include "Freenove_Battery.h"

float batteryVoltage = 0;       //Battery voltage variable
float batteryCoefficient = 4;   //Set the proportional coefficient

//Gets the battery ADC value
int Get_Battery_Voltage_ADC(void)
{
    pinMode(PIN_BATTERY, INPUT);
    int batteryADC = 0;
    for (int i = 0; i < 5; i++)
        batteryADC += analogRead(PIN_BATTERY);
    return batteryADC / 5;
}

//Get the battery voltage value
float Get_Battery_Voltage(void)
{
    int batteryADC = Get_Battery_Voltage_ADC();
    batteryVoltage = (batteryADC / 4096.0  * 3.9 ) * batteryCoefficient;
    return batteryVoltage;
}

void Set_Battery_Coefficient(float coefficient)
{
    batteryCoefficient = coefficient;
}