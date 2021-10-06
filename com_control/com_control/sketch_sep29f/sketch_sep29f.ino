const byte pinR = 11; //pwm
const byte pinG = 10; //pwm
const byte pinB = 9; //pwm
const byte pinAnalog = A0; //가변저항

void setRGB(int r, int g, int b) {
analogWrite(pinR, r);
analogWrite(pinG, g);
analogWrite(pinB, b);
}

void setup() {
  pinMode(pinLED,OUTPUT);
}

void loop() {  
  int value = analogRead(pinAnalog);
  float outValue = value / 1023.*255.;
  if(outValue==0)
  {
    setRGB(255, 0, 0); //red
    delay(1000);
  }
  
  delay(100);
}
