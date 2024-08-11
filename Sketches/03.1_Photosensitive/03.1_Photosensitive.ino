/**********************************************************************
  Filename    : Photosensitive_Sensor.ino
  Product     : Freenove 4WD Car for ESP32
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#define PHOTOSENSITIVE_PIN 33 // Пін до якого під'єднаний фоточутливий сенсор
int photosensitiveADC;        // Змінна для зберігання значень ADC, отримані від фоточутливого сенсора

void setup()
{
  pinMode(PHOTOSENSITIVE_PIN, INPUT); // Налаштувати пін для режиму вводу
  Serial.begin(115200);              // Ініціалізувати Serial і встановити швидкість передачі на 115200
}

void loop()
{
  photosensitiveADC = analogRead(PHOTOSENSITIVE_PIN); // Зчитати значення фоточутливого сенсора
  Serial.print("photosensitiveADC: ");
  Serial.println(photosensitiveADC);                 // Вивести отримане значення
  delay(500);
}
