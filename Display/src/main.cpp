
#include "BluetoothSerial.h"
#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long drawTime = 0;

int distance1;
int distance2;
int distance3;

void setup(void) {
  tft.init();
  tft.setRotation(1);
}
int i = 0;
void loop() {
tft.fillScreen(TFT_PINK);
  


  tft.setTextColor(TFT_RED, TFT_BLUE);
  tft.drawString("Beacon 1",0,0);
  char *intStr = itoa(distance1);
  String strDOne = string(intStr);
  tft.text(strDOne,0,10)
  tft.drawString("Beacon 2",0,50);
  char *intStrI = itoa(distance2);
  String strDTwo = string(intStrI);
  tft.text(strDTwo,0,60);
  tft.drawString("Beacon 3", 0,150);
  char *intStrII = itoa(distance3);
  string strDThree = string(intStrII);
  tft.text(strDTHree,0,60);

  

  
  delay(100);
}
