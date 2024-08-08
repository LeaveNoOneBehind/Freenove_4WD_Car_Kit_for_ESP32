#ifndef FREENOVE_BATTERY_H
#define FREENOVE_BATTERY_H

#define PIN_BATTERY        32        //Set the battery detection voltage pin
#define LOW_VOLTAGE_VALUE  2100      //Set the minimum battery voltage

extern float batteryCoefficient;    //Set the proportional coefficient

int Get_Battery_Voltage_ADC(void);   //Gets the battery ADC value
float Get_Battery_Voltage(void);     //Get the battery voltage value
void Set_Battery_Coefficient(float coefficient);//Set the partial pressure coefficient


#endif //FREENOVE_BATTERY_H
