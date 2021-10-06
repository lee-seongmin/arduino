#include <EEPROM.h>

union
{
  float floatValue;
  byte byteValue[4];
}aUnion, bUnion;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float a = -1.23, b = 4.56;
  aUnionValue = a; bUnionValue = b;
  for(int i=0; i<4; i++)
  {
    aUnion.byteValue[i] = EEPROM.read(i);
  }
  for(int j=4; j<8; j++)
  {
    bUnion.byteValue[j-4] = EEPROM.read(j);
  }
  
}
