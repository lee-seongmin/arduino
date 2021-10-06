#include <EEPROM.h>
int value1 = 2018;
float value2 = 2018.20;
void setup() {
  Serial.begin(9600);
  for(int i=0; i<1024; i++) {EEPROM.write(i,0);} //EEPROM CLEAR 초기화
  EEPROM.put(3,value1); // 2byte
  EEPROM.put(7,value2); // 4byte
}

void loop() {
  int v1; float v2;
  v1 = EEPROM.get(3,value1);
  v2 = EEPROM.get(7,value2);
  Serial.print(v1);
  Serial.print("\t");
  Serial.println(v2);
  delay(2000);
}
