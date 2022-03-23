#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "U8glib.h"

Adafruit_BMP085 bmp;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
#define HOTLED_PIN 2
#define COLDLED_PIN 4
float temperature = 0.0;
void BmpSensorRead(float* temperature);
void DisplayPresTemp(float* temperature);

void setup(void){
  pinMode(HOTLED_PIN,OUTPUT);
  pinMode(COLDLED_PIN,OUTPUT);
  if (!bmp.begin())
  {
    u8g.firstPage();

    do
    {
      u8g.setFont(u8g_font_fub11);
      u8g.setFontRefHeightExtendedText();
      u8g.setDefaultForegroundColor();
      u8g.setFontPosTop();
    }
    while (u8g.nextPage());

    Serial.println("BMP085 sensoru algilanmadi");

    while (1) {}
}
}
void loop(void)
{
  BmpSensorRead(&temperature);
  DisplayPresTemp(&temperature);
  delay(1000);
}
void DisplayPresTemp(float* temperature)
{
    u8g.firstPage();

  do
  {
    u8g.setFont(u8g_font_7x13B);
    u8g.setFontRefHeightExtendedText();
    u8g.setDefaultForegroundColor();
    u8g.setFontPosTop();
    u8g.drawStr(0, 0, "Sicaklik");
    u8g.drawLine(0,20,128,20);
    u8g.setPrintPos(60, 0);
    u8g.print(*temperature);
    u8g.print(" *C");
    u8g.drawStr(0, 30,"IOT - Lab Practice 2");
  }
  while (u8g.nextPage());
  }
void BmpSensorRead(float* temperature)
{
  *temperature = bmp.readTemperature();
  Serial.print("Sıcaklık = ");
  Serial.print(*temperature);
  Serial.println(" *C");
  if (*temperature>25){
    digitalWrite(HOTLED_PIN,HIGH);
    digitalWrite(COLDLED_PIN,LOW);
  }
  else{
    digitalWrite(COLDLED_PIN,HIGH);
    digitalWrite(HOTLED_PIN,LOW);
  }
}
