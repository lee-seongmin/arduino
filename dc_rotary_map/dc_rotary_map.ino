const byte pinMotor = 5;
const byte pinPot = A0; // Potentiometer
void setup() {
  Serial.begin(9600);
}
void loop() {
  int input, value;
  input = analogRead(pinPot);
  value = map(input, 0, 1023, 0, 255);
  //value = input/1023.*255.;
  analogWrite(pinMotor, value);
  Serial.print("Ptn Input = ");
  Serial.print("\t");
  Serial.print(input);
  Serial.print("\t");
  Serial.print("PWM Output = ");
  Serial.print("\t");
  Serial.println(value);
  delay(100);
}
