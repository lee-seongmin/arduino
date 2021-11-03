void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int i=0; i < 255; i++)
  {
    analogWrite(5,i);
    analogWrite(6,0);
    delay(20);
  }
  
  for(int i=255; i > 0; i--)
  {
    analogWrite(5,i);
    analogWrite(6,0);
    delay(20);
  }
  analogWrite(5,0); analogWrite(6,0);
  delay(1000);
  
  for(int i=0; i < 255; i++)
  {
    analogWrite(5,0);
    analogWrite(6,i);
    delay(20);
  }
  for(int i=255; i > 0; i--)
  {
    analogWrite(5,0);
    analogWrite(6,i);
    delay(20);
  }
  analogWrite(5,0); analogWrite(6,0);
  delay(1000);
}
