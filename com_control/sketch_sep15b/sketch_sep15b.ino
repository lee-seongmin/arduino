const byte pinAnalog=A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //analogReference(EXTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;
  value = analogRead(pinAnalog);
  float volt= 5.0*value/1023.0;
  // float volt=3.3*value/1023.0;
  // Serial.print(value); //Serial.print('t');
  Serial.println(value); //Serial.println("V");
  delay(200);
}
