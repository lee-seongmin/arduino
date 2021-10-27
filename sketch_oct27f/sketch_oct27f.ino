const byte pinBtn = 2;
const byte pinLED =13;
volatile int state = LOW;

void ledControl(){
  byte before = digitalRead(pinBtn);
  if(before!=1) //tact스위치를 쓸 때 필요한 조건
  {
    delay(1);
    byte cur = digitalRead(pinBtn);
    if(cur==before)
    {
      state = ! state;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBtn,2);
  pinMode(pinLED,1);
  attachInterrupt(0,ledControl,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinLED,state);
}
