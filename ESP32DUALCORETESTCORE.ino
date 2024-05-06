#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h>  // Hardware-specific library for ST7789
#include <SPI.h>
#include <WiFi.h>
#include "time.h"
#define TFT_DC 12    //A0
#define TFT_CS 13    //CS
#define TFT_MOSI 14  //SDA
#define TFT_CLK 27   //SCK
#define TFT_RST 0
#define TFT_MISO 0
String ssid     = "";
String password = "";

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);
float p = 3.1415926;
int count = 0;
int newcount;
String addr;
String tot;
String oup;
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
void setup() {
  oup = "";
  Serial.begin(115200);
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLUE);
  delay(500);
  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_WHITE);
  tft.println("Standalone GPU:");
  delay(2000);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  tft.println("Enter SSID:");
  delay(3000);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(10, 150);
  delay(500);
  keyboard();
  delay(10);
  ssid=oup;
  oup = "";
  tot ="";
  delay(50);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  tft.println("Enter Password:");
  delay(3000);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(10, 150);
  delay(500);
  oup = "";
  tot="";
  delay(50);
  keyboard();
  delay(10);
  password = oup;
  oup = "";
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  tft.print(ssid);
  tft.println();
  tft.print(password);
  delay(3000);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  initWiFi();
  delay(3000);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  tft.println("Connecting to "+ ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      tft.print(".");
  }
  tft.println("CONNECTED");
  delay(1000);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  delay(5000);
}
void keyboard() {
  for (int i = 1; i <= 128000; i++) {
    if (touchRead(15) <= 22) {
      newcount = count + 1;
      if (newcount != count) {
        delay(15);
        switch (newcount) {
          case 1:
            break;
          case 2:
            addr = "a";
            break;
          case 3:
            addr = "A";
            break;
          case 4:
            addr = "b";
            break;
          case 5:
            addr = "B";
            break;
          case 6:
            addr = "c";
            break;
          case 7:
            addr = "C";
            break;
          case 8:
            addr = "d";
            break;
          case 9:
            addr = "D";
            break;
          case 10:
            addr = "e";
            break;
          case 11:
            addr = "E";
            break;
          case 12:
            addr = "f";
            break;
          case 13:
            addr = "F";
            break;
          case 14:
            addr = "g";
            break;
          case 15:
            addr = "G";
            break;
          case 16:
            addr = "h";
            break;
          case 17:
            addr = "H";
            break;
          case 18:
            addr = "i";
            break;
          case 19:
            addr = "I";
            break;
          case 20:
            addr = "j";
            break;
          case 21:
            addr = "J";
            break;
          case 22:
            addr = "k";
            break;
          case 23:
            addr = "K";
            break;
          case 24:
            addr = "l";
            break;
          case 25:
            addr = "L";
            break;
          case 26:
            addr = "m";
            break;
          case 27:
            addr = "M";
            break;
          case 28:
            addr = "n";
            break;
          case 29:
            addr = "N";
            break;
          case 30:
            addr = "o";
            break;
          case 31:
            addr = "O";
            break;
          case 32:
            addr = "p";
            break;
          case 33:
            addr = "P";
            break;
          case 34:
            addr = "q";
            break;
          case 35:
            addr = "Q";
            break;
          case 36:
            addr = "r";
            break;
          case 37:
            addr = "R";
            break;
          case 38:
            addr = "s";
            break;
          case 39:
            addr = "S";
            break;
          case 40:
            addr = "t";
            break;
          case 41:
            addr = "T";
            break;
          case 42:
            addr = "u";
            break;
          case 43:
            addr = "U";
            break;
          case 44:
            addr = "v";
            break;
          case 45:
            addr = "V";
            break;
          case 46:
            addr = "w";
            break;
          case 47:
            addr = "W";
            break;
          case 48:
            addr = "x";
            break;
          case 49:
            addr = "X";
            break;
          case 50:
            addr = "y";
            break;
          case 51:
            addr = "Y";
            break;
          case 52:
            addr = "z";
            break;
          case 53:
            addr = "Z";
            break;
          case 54:
            addr = " ";
            break;
          case 55:
            addr = "1";
            break;
          case 56:
            addr = "2";
            break;
          case 57:
            addr = "3";
            break;
          case 58:
            addr = "4";
            break;
          case 59:
            addr = "5";
            break;
          case 60:
            addr = "6";
            break;
          case 61:
            addr = "7";
            break;
          case 62:
            addr = "8";
            break;
          case 63:
            addr = "9";
            break;
          case 64:
            addr = "0";
            break;
          default:
            newcount = 0;
            break;
        }
        count = newcount;
      }
      tft.fillScreen(ST77XX_BLUE);
      tft.setCursor(10, 150);
      delay(10);
      tft.print(addr);
    }
    if (touchRead(4) <= 26) {
      tot += addr;
      tft.fillScreen(ST77XX_BLUE);
      tft.setCursor(0, 0);
      tft.print(tot);
    }
    if (touchRead(32) <= 22) {
      tft.fillScreen(ST77XX_BLUE);
      oup = tot;
      count = 0;
      newcount = 0;
    }
    if (touchRead(33) <= 22) {
      tft.fillScreen(ST77XX_BLUE);
      tft.setTextColor(ST77XX_GREEN);
      oup = tot;
      tft.setCursor(0, 0);
      tft.print(oup);
      delay(800);
      tft.fillScreen(ST77XX_BLUE);
      tft.setCursor(0, 0);
      tft.print(oup);
      delay(800);
      tft.fillScreen(ST77XX_BLUE);
      tft.setCursor(0, 0);
      tft.print(oup);
      delay(800);
      tft.fillScreen(ST77XX_BLUE);
      tft.setCursor(0, 0);
      tft.print(oup);
      delay(800);
      tft.fillScreen(ST77XX_BLUE);
      tft.setCursor(0, 0);
      delay(10);
      tft.setTextColor(ST77XX_WHITE);
      break;
    }
    delay(100);
  }
}
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  tft.setCursor(0,0);
  tft.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    tft.print('.');
    delay(1000);
  }
  tft.println(WiFi.localIP());
}
void printLocalTime(){
  for(int x = 1; x<=16000;x++){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    tft.fillScreen(ST77XX_BLUE);
    tft.setCursor(0,0);
    tft.println("Failed to obtain time");
    delay(500);
    continue;
  }else{
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(0,0);
  tft.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  delay(500);
  break;
  }
  }
}
void loop() {
}
