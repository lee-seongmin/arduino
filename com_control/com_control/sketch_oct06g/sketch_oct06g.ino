#include <EEPROM.h>
union
{
  long longValue; //4byte
  byte byteValue[4];
}aUnion, bUnion;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  long a,b;

  for(int i=0; i<4; i++)
  {
    aUnion.byteValue[i] = EEPROM.read(i);
  }
  for(int j=4; j<8; j++)
  {
    bUnion.byteValue[j-4] = EEPROM.read(j);
  }
  a = aUnion.longValue;
  b = bUnion.longValue;
  Serial.print("a :" + String(a)+ "\t");
  Serial.println("b :" + String(b));
  delay(2000);
}
