const byte pinLED = 13;
volatile int stateLED = LOW;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(2,2); //INPUT_PULLUP =2
  pinMode(3,2); //INPUT_PULLUP
  attachInterrupt(0, btnUp, FALLING);
  attachInterrupt(1, btnDown, FALLING);
}
void loop() {
  digitalWrite(pinLED, stateLED);
  delay(500);
}
void btnUp() {
  stateLED = HIGH;
}
void btnDown() {
  stateLED = LOW;
}
