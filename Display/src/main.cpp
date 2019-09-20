#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long drawTime = 0;

void setup(void) {
  tft.init();
  tft.setRotation(1);
}
int i = 0;
void loop() {
tft.fillScreen(TFT_PINK);
  


  tft.setTextColor(TFT_RED, TFT_BLUE);
  i++;
  tft.setCursor(i,i);
  tft.print("Hello World!");

  
  delay(100);
}
