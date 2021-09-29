const int pinLEDs[3]={13,8,7};
const int pinBtns[3]={2,3,4};

void setup(){
  for(int i=0; i<3; i++){
    pinMode(pinLEDs[i], OUTPUT);
    pinMode(pinBtns[i], INPUT_PULLUP);
  }
}
void loop(){
  for(int i=0; i<3; i++){
    if(!digitalRead(pinBtns[i])==HIGH)
      digitalWrite(pinLEDs[i],HIGH);
    else
      digitalWrite(pinLEDs[i], LOW);      
  }
}
