#include <EEPROM.h>
union{
  long longValue;
  byte byteValue[4];
}aUnion, bUnion;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long a = -123456, b=123456;
  
  aUnion.longValue = a;
  bUnion.longValue = b;
  for(int i=0; i<4; i++)
  {
    EEPROM.write(i, aUnion.byteValue[i]);
  }
  
  for(int j=4; j<8; j++)
  {
    EEPROM.write(j, bUnion.byteValue[j-4]);
  }
}
