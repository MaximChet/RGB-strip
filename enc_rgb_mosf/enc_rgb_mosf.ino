#define CLK 2
#define DT 4
#define SW 5

#include "GyverEncoder.h"
Encoder enc1(CLK, DT, SW);
int value = 0;
int VALUE_MAX = 255;
int VALUE_MIN = 0;
int valuemode = 0;
int VALUEMODE_MAX = 7;
int VALUEMODE_MIN = 0;
//мосфеты
int blue = 3;
int red = 9;
int green = 10;
//адресный лед
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 7, NEO_GRB + NEO_KHZ800);
int o = 1;

void setup() {
  Serial.begin(9600);
  enc1.setType(TYPE2);
  //мосфеты
  pinMode(blue, OUTPUT); //Устанавливаем 13 контакт в режим ввода
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  //адресный лед
  pixels.begin();
 
}

void loop() {
  // обязательная функция отработки. Должна постоянно опрашиваться
  enc1.tick();
  if (enc1.isRight()) value++; // если был поворот направо, увеличиваем на 1
  if (enc1.isLeft()) value -= 5; // если был поворот налево, уменьшаем на 1
  if (enc1.isRightH()) valuemode++; // если было удержание + поворот направо, увеличиваем на 5
  if (enc1.isLeftH()) valuemode--; // если было удержание + поворот налево, уменьшаем на 5
  if (value >= VALUE_MAX) value = VALUE_MAX;
  if (value <= VALUE_MIN) value = VALUE_MIN;
  if (valuemode >= VALUEMODE_MAX) valuemode = VALUEMODE_MAX;
  if (valuemode <= VALUEMODE_MIN) valuemode = VALUEMODE_MIN;
  if (enc1.isTurn()) { // если был совершён поворот (индикатор поворота в любую сторону)
    Serial.println(value); // выводим значение при повороте
    Serial.println(valuemode);
    switch (valuemode) {
      case 0:
        analogWrite(3, value);
        analogWrite(9, value);
        analogWrite(10, value);
        for (int o; o < 1; o++) {
          
          pixels.setPixelColor(o, pixels.Color(20, 20, 20));
          pixels.show(); }
          break;
        case 1:
          analogWrite(3, value);
          analogWrite(9, value);
          analogWrite(10, 0);
          for (int o; o < 1; o++) {
          
          pixels.setPixelColor(o, pixels.Color(0, 0, 20));
          pixels.show(); }
          break;
        case 2:
          analogWrite(3, value);
          analogWrite(9, 0);
          analogWrite(10, value);
          for (int o; o < 1; o++) {
          
          pixels.setPixelColor(o, pixels.Color(0, 20, 0));
          pixels.show(); }
          break;
        case 3:
          analogWrite(3, 0);
          analogWrite(9, value);
          analogWrite(10, value);
          for (int o; o < 1; o++) {
          
          pixels.setPixelColor(o, pixels.Color(20, 0, 0));
          pixels.show(); }
          break;
        case 4:
          analogWrite(3, 0);
          analogWrite(9, 0);
          analogWrite(10, value);
          break;
        case 5:
          analogWrite(3, value);
          analogWrite(9, 0);
          analogWrite(10, 0);
          break;
        case 6:
          analogWrite(3, 0);
          analogWrite(9, value);
          analogWrite(10, 0);
          break;
        case 7:
          analogWrite(3, 0);
          analogWrite(9, 0);
          analogWrite(10, value);
          break;
        }
    }
  }
