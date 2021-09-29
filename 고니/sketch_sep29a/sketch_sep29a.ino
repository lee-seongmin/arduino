const byte pinPWM=6; //pwm

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value;

  if(Serial.available())
  {
    //value = Serial.read();
    value = Serial.parseInt(); //Serial.parseInt()  
    value = constrain(value, 0 ,255);
    analogWrite(pinPWM,value);
  }
  Serial.println("Enter value (0~255) :");
  Serial.println(value);
  delay(1000);
}
