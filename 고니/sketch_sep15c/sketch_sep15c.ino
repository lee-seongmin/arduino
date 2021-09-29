const byte pinLED = 13;
const byte pinCds = A0;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;
  
  value = analogRead(pinCds);

  if(value < 500)
    digitalWrite(pinLED,HIGH);
  else
    digitalWrite(pinLED,LOW);
}
