#include <SoftwareSerial.h>
SoftwareSerial btATSerial(9, 8); // RX, TX

void setup() {
  btATSerial.begin(38400); // 38400 : AT mode of HC-05
  Serial.begin(9600); // Baud rate 9600 of Serial Monitor
  Serial.println("Enter AT commands : ");
}
void loop() {
  if (btATSerial.available())
    Serial.write(btATSerial.read());
  if (Serial.available())
    btATSerial.write(Serial.read());
}
