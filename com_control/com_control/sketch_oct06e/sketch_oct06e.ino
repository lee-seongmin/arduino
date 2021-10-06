#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte a=12, b=24;

  EEPROM.write(0,a);
  EEPROM.write(1,b);
  Serial.print("a :" + String(a) + "\t");
  Serial.println("b :" + String(b));
  delay(1000);
}
