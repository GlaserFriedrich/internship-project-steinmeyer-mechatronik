#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI0
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define SDA_PIN D5
#define SCL_PIN D6

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL_PIN, SDA_PIN, U8X8_PIN_NONE);

int sensorpin = A0;
int sensorvalue = 0;
int sensorwert;
int Max = 20;
int Min = 20;

void setup(void) {
 u8g2.begin();
}

void loop(void) {

  sensor();

  if (sensorvalue > Max) {
    Max = sensorvalue;
  } else if (sensorvalue < Min) {
    Min = sensorvalue;
  }

  String maxtemp = "Max" + String(Max);
  String mintemp = "Min" + String(Min);
  char Maximum[10];
  char Minimum[10];
  maxtemp.toCharArray(Maximum, sizeof(Maximum));
  mintemp.toCharArray(Minimum, sizeof(Minimum));

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_littlemissloudonbold_tr);

  u8g2.drawStr (0,10,"LUFTFEUCHTIGKEIT");

  u8g2.drawBox(0, 25, sensorvalue, 10);
  u8g2.drawStr (100,35,"%");

  u8g2.drawTriangle(0,64 ,  16,64 , 8,48);
  u8g2.drawStr(17, 64, Maximum);
  u8g2.drawTriangle(59,48 ,  75,48 , 67,64);
  u8g2.drawStr(72, 64, Minimum);

  u8g2.sendBuffer();
  delay(1000);
}

void sensor () {
  sensorwert = analogRead(sensorpin);
  sensorvalue = map(sensorwert, 0, 1023, 0, 100);
}