#include <Arduino.h>

void setup() {
  pinMode(GPIO_NUM_13, OUTPUT);
}

void loop() {
  digitalWrite(GPIO_NUM_13, HIGH);
  delay(300);
  digitalWrite(GPIO_NUM_13, LOW);
  delay(300);

}