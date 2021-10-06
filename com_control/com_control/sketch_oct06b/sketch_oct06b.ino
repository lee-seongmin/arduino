#include <EEPROM.h>
union
{
  int intValue;
  byte byteValue[sizeof(int)];
}intUnion;
int iNumber;

void setup() {
  Serial.begin(9600);
}

void loop() {
  intUnion.byteValue[0] = EEPROM.read(0);
  intUnion.byteValue[1] = EEPROM.read(1);
  iNumber = intUnion.intValue;
  Serial.print("highByte : " + String(intUnion.byteValue[1]) + "\t");
  Serial.print("lowByte : " + String(intUnion.byteValue[0]) + "\t");
  Serial.println("16bit Integer : " + String(iNumber) + "\t");
  delay(1000);
}
