
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

  

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
