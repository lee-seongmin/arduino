#include <Wire.h> //Slave of I2C

void receiveEvent(int bytes)
{
  int data;
  data = Wire.read();
  Serial.println(data);
}
void requestEvent() 
{ 
  int data=235;
  Wire.write(data); 
}
void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent); // receive from Master
  Wire.onRequest(requestEvent); // send to Master
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
