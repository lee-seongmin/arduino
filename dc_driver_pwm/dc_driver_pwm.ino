void setup() {
  // put your setup code here, to run once:
}

void loop() {
  analogWrite(5,128);
  analogWrite(6,0);
  delay(1000);
  analogWrite(5,0);
  analogWrite(6,128);
  delay(1000);
}
