/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Use buzzer
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include <Freenove_4WD_Car_For_ESP32.h>

void setup() {
  Buzzer_Setup();    // Функція ініціалізації пищалки
  Buzzer_Alert(4, 3);// Налаштування пищалки, таким чином, щоб були 4 короткі звукові сигнали, що повторюються 3 рази
}

void loop() {
  delay(1000);
}
