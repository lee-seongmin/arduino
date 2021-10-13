const byte pinSw = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSw, INPUT_PULLUP); // INPUT_PULLUP=2랑 똑같다.
}

void loop() {
  // put your main code here, to run repeatedly:
  int data;

  data = digitalRead(pinSw);
  Serial.write(data);
  delay(200);
}
