#include <Wire.h> // Master of I2C
void setup() 
{ 
  Wire.begin();  // Master
  Serial.begin(9600); 
}
void loop() 
{ 
  int data=234; 
  Wire.beginTransmission(8);// Slave #8 
  Wire.write(data); 
  Wire.endTransmission(); 
  Wire.requestFrom(8, 1); // request 1 bytes
  if(Wire.available())
  {
    data = Wire.read();
      
    if (data != 0)
    {
    
      Serial.println(data);//Serial.write(data);
    }
  } 
  
  delay(100); 
}
