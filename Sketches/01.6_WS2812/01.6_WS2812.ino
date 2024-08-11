/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Use WS2812.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/

#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  12    // Кількість світлодіодів WS2812
#define LEDS_PIN  	32    // Номер піна для ESP32
#define CHANNEL	    0     // Канал для керування WS2812

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();		  // Ініціалізувати WS2812
  strip.setBrightness(10);// Встановити яскравість WS2812
}

void loop() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
		strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));// Встановити колір для WS2812
    }
    strip.show();	      // Показати виставлені кольори на стрічці
    delay(5);
  }  
}
