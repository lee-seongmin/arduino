#include <SoftwareSerial.h>
SoftwareSerial btSerial(9, 8); // TX, RX
const byte pinLED = 13;

void setup() {
  btSerial.begin(9600);
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}
void loop() {
int btValue;
if (btSerial.available()) {
    btValue = btSerial.read() - '0'; // ASCII code : ‘1’=49, ‘0’=48
    Serial.println(btValue);
    if (btValue == 0)
      digitalWrite(pinLED, LOW);
    else if (btValue == 1)
      digitalWrite(pinLED, HIGH);
  }
}
