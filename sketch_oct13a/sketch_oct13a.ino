const byte pinLED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int stateBtn;

  if(Serial.available())
  {
    stateBtn = Serial.read();
  }
  if(stateBtn ==HIGH)
    digitalWrite(pinLED,HIGH);
  else
    digitalWrite(pinLED,LOW);
  delay(200);
}
