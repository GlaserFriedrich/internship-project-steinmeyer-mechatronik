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
void setup(void) {
 u8g2.begin();
}

int mittex = 64;
int mittey = 32;
int AbstandLXL = -3;
int AbstandLXR =  3;
int AbstandLYO = -3;
int AbstandLYU =  3;
bool Rkleiner;
void loop(void) {
  
 

  u8g2.clearBuffer();
  u8g2.drawLine((mittex + AbstandLXL),mittey ,(mittex + AbstandLXR) ,mittey );
  u8g2.drawLine(mittex, (mittey + AbstandLYO), mittex, (mittey + AbstandLYU) );
  u8g2.sendBuffer();

  if (AbstandLXL == -20 ){
    Rkleiner = true;
  } else if (AbstandLXL == -3) {
    Rkleiner = false;
  } 

  if (Rkleiner == true)  {
    AbstandLXL++;

  } else if (Rkleiner == false) {
    AbstandLXL--;
  } 

  if (Rkleiner == true) {
    AbstandLXR--;
  } else if (Rkleiner == false) {
    AbstandLXR++;
  }

  if (Rkleiner == true) {
    AbstandLYO++;
  } else if (Rkleiner == false) {
    AbstandLYO--;
  }

  if (Rkleiner == true) {
    AbstandLYU--;
  } else if (Rkleiner == false) {
    AbstandLYU++;
  }
  

}
