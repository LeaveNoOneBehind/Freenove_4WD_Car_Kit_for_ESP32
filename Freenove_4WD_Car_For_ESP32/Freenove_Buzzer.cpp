#include <Arduino.h>
#include "Freenove_Buzzer.h"

void Buzzer_Setup(void)
{
    pinMode(PIN_BUZZER, OUTPUT);
    // ledcSetup(BUZZER_CHN, BUZZER_FREQUENCY, 10);
    // ledcAttachPin(PIN_BUZZER, BUZZER_CHN);
    ledcAttach(PIN_BUZZER, BUZZER_FREQUENCY, 10);
    ledcWriteTone(PIN_BUZZER, 0);
    delay(10);
}

//Buzzer alarm function
void Buzzer_Alert(int beat, int rebeat)
{
    beat = constrain(beat, 1, 9);
    rebeat = constrain(rebeat, 1, 255);
    for (int j = 0; j < rebeat; j++)
    {
        for (int i = 0; i < beat; i++)
        {
            ledcWriteTone(PIN_BUZZER, BUZZER_FREQUENCY);
            delay(100);
            ledcWriteTone(PIN_BUZZER, 0);
            delay(100);
        }
        delay(500);
    }
    ledcWriteTone(PIN_BUZZER, 0);
}

//Buzzer variable frequency
void Buzzer_Variable(bool enable, int frequency)
{
  if (enable == 1)
  {
    frequency = constrain(frequency, 0, 10000);
    ledcWriteTone(PIN_BUZZER, frequency);
  }
  else
    ledcWriteTone(PIN_BUZZER, 0);
}

//Buzzer alarm function
void Buzzer_Alarm(bool enable)
{
  if (enable == 0)
    ledcWriteTone(PIN_BUZZER, 0);
  else
    ledcWriteTone(PIN_BUZZER, BUZZER_FREQUENCY);
}
