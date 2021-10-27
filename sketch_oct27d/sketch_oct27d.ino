const byte pinLED = 13;
volatile int stateLED = LOW;

void setup() {
  pinMode(pinLED, OUTPUT);
  attachInterrupt(0, btnUp, FALLING);
  attachInterrupt(1, btnDown, RISING);
}
void loop() {
  digitalWrite(pinLED, stateLED);
  delay(1000);
}
void btnUp() {
  stateLED = LOW;
}
void btnDown() {
  stateLED = HIGH;
}
