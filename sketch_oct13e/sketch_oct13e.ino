#include <SPI.h>   // Master of SPI 
const int pinSS = 10;      //Slave Select
void setup () 
{ 
  pinMode(pinSS, OUTPUT); 
  digitalWrite(pinSS, HIGH); 
  SPI.begin(); 
  Serial.begin(9600); 
}
void loop () 
{ 
  int data; 
  if (Serial.available()) 
  { data = Serial.read(); 
    digitalWrite(pinSS, LOW);
    SPI.transfer(data); 
    digitalWrite(pinSS, HIGH); 
  } 
  else 
  {
    digitalWrite(pinSS, LOW); 
    data = SPI.transfer(NULL); 
    digitalWrite(pinSS, HIGH); 
    if (data != NULL) 
      Serial.write(data); 
  } 
  delay(100); 
}
