const byte timer[6]= {5,6,9,10,3,11};
byte value=10;

void setup() {
for (int i=0; i < 6; i++)
{
  pinMode(timer[i],1);  
}
Serial.begin(9600);
Serial.println("Input your value(0~255)");
}

void loop() {
  if(Serial.available())
  {
    value = Serial.parseInt();
    value = constrain(value, 0 ,255);
    Serial.print("Your input is ");
    Serial.println(value);  
  }
  for (int i=0; i < 6; i++)
  {
    analogWrite(timer[i],value);  
  }

}
