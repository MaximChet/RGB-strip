//#define CLK 2
//#define DT 5
//#define SW 4

//#include "GyverEncoder.h"
//Encoder enc1(CLK, DT, SW);
//int value = 0;
//int VALUE_MAX = 255;
//int VALUE_MIN = 0;
//int valuemode = 0;
//int VALUEMODE_MAX = 7;
//int VALUEMODE_MIN = 0;
//мосфеты
int blue1 = 3;
int red1 = 9;
int green1 = 10;
//Гамма

int red; // переменная для хранения R-составляющей цвета
int green; // переменная для хранения G-составляющей цвета
int blue; // переменная для хранения B-составляющей цвета

//адресный лед
//#include <Adafruit_NeoPixel.h>
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(300, 7, NEO_GRB + NEO_KHZ800);
//int o = 1;

void setup() {
  Serial.begin(9600);
  //enc1.setType(TYPE2);
  //мосфеты
  pinMode(blue1, OUTPUT); //Устанавливаем 13 контакт в режим ввода
  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);
  //адресный лед
  //pixels.begin();
 
}

//void loop() {
  // обязательная функция отработки. Должна постоянно опрашиваться
//  enc1.tick();
//  if (enc1.isRight()) value++; // если был поворот направо, увеличиваем на 1
//  if (enc1.isLeft()) value -=5; // если был поворот налево, уменьшаем на 1
//  if (enc1.isRightH()) valuemode++; // если было удержание + поворот направо, увеличиваем на 5
//  if (enc1.isLeftH()) valuemode--; // если было удержание + поворот налево, уменьшаем на 5
//  if (value >= VALUE_MAX) value = VALUE_MAX;
//  if (value <= VALUE_MIN) value = VALUE_MIN;
//  if (valuemode >= VALUEMODE_MAX) valuemode = VALUEMODE_MAX;
//  if (valuemode <= VALUEMODE_MIN) valuemode = VALUEMODE_MIN;
//  if (enc1.isTurn()) { // если был совершён поворот (индикатор поворота в любую сторону)
//    Serial.println(value); // выводим значение при повороте
//    Serial.println(valuemode);   
//    
//    }
//  }

void loop()
{
red = 31;
// от красного к желтому
for(green=0;green<=31;green++){
analogWrite(green1,green);
delay(100);}
// от желтому к зеленому
for(red=31;red>=0;red--){
analogWrite(red1,red);
delay(100);}
// от зеленого к голубому
for(blue=0;blue<=31;blue++){
analogWrite(blue1,blue);
delay(100);}
// от голубого к синему
for(green=31;green>=0;green--){
analogWrite(green1,green);
delay(100);}
// от синего к фиолетовому
for(red=0;red<=31;red++){
analogWrite(red1,red);
delay(100);}
// от фиолетового к красному
for(blue=31;blue>=0;blue--){
analogWrite(blue1,blue);
delay(100);}
//
for(red=31;red=0;red){
analogWrite(red1,red);
delay(100);}
} // функция установки цвета RGB-светодиода
