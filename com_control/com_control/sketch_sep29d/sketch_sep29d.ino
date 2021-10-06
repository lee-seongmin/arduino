const byte pinAnalog = A0;
const byte pinLED = 11;//pwm

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(pinAnalog);
  float outValue = value / 1023.*255.;
  analogWrite(pinLED, outValue);
  delay(100);                                              
}
