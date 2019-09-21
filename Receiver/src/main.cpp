
#include "BluetoothSerial.h"
#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;
 
TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long drawTime = 0;

int distance1 = 1;
int distance2 = 2;
int distance3 = 3;

void setup(void) {
  tft.init();
  tft.setRotation(1);
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}
int i = 0;
void loop() {
tft.fillScreen(TFT_PINK);
  


  tft.setTextColor(TFT_RED, TFT_BLUE);
  tft.drawString("Beacon 1",0,0);
  tft.drawNumber(distance1,10,10);
  tft.drawString("Beacon 2",0,50);
  tft.drawNumber(distance2,10,60);
  tft.drawString("Beacon 3", 0,140);
  tft.drawNumber(distance3,10,150);

  

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
