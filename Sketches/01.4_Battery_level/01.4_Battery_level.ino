/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Read battery voltage.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  Serial.begin(115200);                     // Встановити швидкість передачі даних по Serial
}

void loop() {
  Serial.print("Battery ADC : ");
  Serial.println(Get_Battery_Voltage_ADC());// Отримати "сире" значення ADC батареї
  Serial.print("Battery Voltage : ");
  Serial.print(Get_Battery_Voltage());      // Отримати перетворене значення напруги батареї у вольтах
  Serial.println("V");
  delay(300);
}
