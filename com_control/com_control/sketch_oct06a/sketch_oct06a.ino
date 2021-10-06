#include <EEPROM.h>
union
{
  int intValue;
  byte byteValue[sizeof(int)];
}intUnion;
int iNumber = 2018;

void setup() {
  Serial.begin(9600);
}

void loop() {
  intUnion.intValue = iNumber;
  EEPROM.write(0,intUnion.byteValue[0]);
  EEPROM.write(1,intUnion.byteValue[1]);
  Serial.print("16bit Integer : " + String(iNumber)+"\t");
  Serial.print("highByte : " + String(intUnion.byteValue[1])+"\t");
  Serial.println("lowByte : " + String(intUnion.byteValue[0]));
  delay(1000);
}
