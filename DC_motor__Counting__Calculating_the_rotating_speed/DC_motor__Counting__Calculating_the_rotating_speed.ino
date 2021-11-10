const byte pinCLK=2, pinDT=3;
const float DELAY_TIME=100, PULSE_REV=26, RATIO=30, RPM=60;
float Angvel, tim;
volatile int count=0;

void valueUP() 
{
  byte chA = digitalRead(pinCLK),chB = digitalRead(pinDT);
  if(chA !=chB)
  {
    count++;
  }
  else
  {
    count--;
  }
}

float angvel()
{
  signed int OldPos = count;
  delay(DELAY_TIME);
  signed int NewPos = count;
  if(abs(NewPos-OldPos) < 30000)
  {
    float dVal = ((float)(NewPos-OldPos) / DELAY_TIME) *1000.0;
    float angVel = dVal / PULSE_REV / RATIO*RPM;
    return angVel;
  }
}

void setup()
{
  pinMode(pinCLK,INPUT_PULLUP);
  pinMode(pinDT,INPUT_PULLUP);
  attachInterrupt(0,valueUP,CHANGE);
  Serial.begin(38400);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Angvel = angvel();
  //Serial.print("Counter value is: ");
  Serial.print(count);
  //Serial.print(" Angular Velocity is: ");  
  Serial.print(Angvel);
  //Serial.println("[rpm]");
}
