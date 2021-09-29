const byte pinLED = 11;//pwm
const byte pinAnalog = A0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<256; i+=5)
  {
    analogWrite(pinLED,i);
    delay(100);
  }
  analogWrite(pinLED,0);
  delay(1000);

    for(int i=255; i>=0; i-=5)
  {
    analogWrite(pinLED,i);
    delay(100);
  }
  analogWrite(pinLED,0);
  delay(1000);
}
