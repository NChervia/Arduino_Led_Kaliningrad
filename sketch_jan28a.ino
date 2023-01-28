#include "Adafruit_NeoPixel.h"// Подключаем библиотеку Adafruit NeoPixel.


#define LED_LAG  20 //Количество светодиодов в задержки.
#define LED_COUNT1 100// Указываем, какое количество пикселей у нашей ленты.
#define LED_PIN1 6// Указываем, к какому порту подключен вход ленты DIN.
Adafruit_NeoPixel stripFirst = Adafruit_NeoPixel(LED_COUNT1, LED_PIN1, NEO_GRB + NEO_KHZ800);// Создаем переменную strip для управления нашей лентой.
///////////////////////////////////////////////////////////////////////////////////////////// Первая лента

#define LED_COUNT2 100// Указываем, какое количество пикселей у нашей ленты.
#define LED_PIN2 7 // Указываем, к какому порту подключен вход ленты DIN.
Adafruit_NeoPixel stripSecond = Adafruit_NeoPixel(LED_COUNT2, LED_PIN2, NEO_GRB + NEO_KHZ800);// Создаем переменную strip для управления нашей лентой.
///////////////////////////////////////////////////////////////////////////////////////////// Вторая лента

#define LED_COUNT3 100// Указываем, какое количество пикселей у нашей ленты.
#define LED_PIN3 8// Указываем, к какому порту подключен вход ленты DIN.
Adafruit_NeoPixel stripThird = Adafruit_NeoPixel(LED_COUNT3, LED_PIN3, NEO_GRB + NEO_KHZ800);// Создаем переменную strip для управления нашей лентой.
/////////////////////////////////////////////////////////////////////////////////////////////

 
void setup()
{
  // Инициализируем ленту.
  stripFirst.begin();
  stripSecond.begin();
  stripThird.begin();
  // Выключаем все светодиоды.
  for (int i = 0; i < LED_COUNT1; i++)
  {
    stripFirst.setPixelColor(i, stripFirst.Color(0, 0, 0)); // Черный цвет, т.е. выключено.
  }
  for (int i = 0; i < LED_COUNT2; i++)
  {
    stripSecond.setPixelColor(i, stripSecond.Color(0, 0, 0)); // Черный цвет, т.е. выключено.
  }
    for (int i = 0; i < LED_COUNT3; i++)
  {
    stripThird.setPixelColor(i, stripThird.Color(0, 0, 0)); // Черный цвет, т.е. выключено.
  }

  stripFirst.show();
  stripSecond.show();// Передаем цвета ленте.
  stripThird.show();
  int count=0;
}
 
void loop()
{
  for (int i = 0; i < (LED_COUNT1+LED_LAG+LED_LAG); i++)///Включение всех трех с задержкой
  {
    if(i<LED_COUNT1)///Включение первой
    {
    stripFirst.setPixelColor(i, stripFirst.Color(255, 255, 255));
    }
    if((i>LED_LAG)&&(i<LED_LAG+LED_COUNT2))///Включение второй
    {
      int y=i-LED_LAG;
      stripSecond.setPixelColor(y, stripSecond.Color(255, 255, 255));
    }
    if((i>LED_LAG+LED_LAG)&&(i<LED_LAG+LED_LAG+LED_COUNT3))///Включение третьей
    {
      int x=i-LED_LAG-LED_LAG;
      stripThird.setPixelColor(x, stripThird.Color(255, 255, 255));

    }
    stripThird.show();
    stripSecond.show();// Передаем цвета ленте.
    stripFirst.show();
    delay(500);
  }
delay(500);

  for (int i = (LED_COUNT1+LED_LAG+LED_LAG); i > 0 ; i--)///Выключение всех трех с задержкой
  {
    if(i<LED_COUNT1)///Выключение первой
    {
    stripFirst.setPixelColor(i, stripFirst.Color(0, 0, 0));
    }
    if((i<LED_LAG+LED_COUNT2)&&(i>LED_LAG))///Выключение второй
    {
      int y=i-LED_LAG;
      stripSecond.setPixelColor(y, stripSecond.Color(0, 0, 0));
    }
    if(i>LED_LAG+LED_LAG)///Выключение третьей
    {
      int x=i-LED_LAG-LED_LAG;
      stripThird.setPixelColor(x, stripThird.Color(0, 0, 0));

    }
    stripThird.show();
    stripSecond.show();// Передаем цвета ленте.
    stripFirst.show();
    delay(500);
  }



}