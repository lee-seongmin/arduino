const byte pinCLK = 2;
const byte pinDT = 3;
const byte reset = 4;
const byte DELAY_TIME = 50; //각속도를 계산하기 위한 델타t
const byte PULSE_REV = 13;
float AngVel, tim;
volatile int count = 0;

void valueUP() // Calculate the counter numbers (CW/CCW)
{
  if(digitalRead(pinCLK)) //만약 2번이 하이라면 그러면
  {
    if(digitalRead(pinDT)=HIGH) 
    {
      count++;// 카운터를 증가시킨다면 카운터는 시계방향
    }
    else
    {
      count--; // 카운터를 감소시킨다면 카운터는 시계반대방향
    }
  }
}

float angvel()
{
  signed int OldPos = count;
  delay(DELAY_TIME);
  signed int NewPos = count;
  if(abs(NewPos - OldPos) < 30000)
  {
    float dVal = ((float)(NewPos - OldPos) / DELAY_TIME) * 1000.0;
    float angVel = dVal / PULSE_REV; // in rev/sec
    // 선속도를 구하고 싶다면 double velocity = (angVel * WHEEL_CIRCUMFERENCE);in mm/sec
    return angVel;
  }
}
void setup() 
{
  pinMode(pinCLK,INPUT);
  pinMode(pinDT,INPUT);
  pinMode(reset,INPUT);
  attachInterrupt(0,valueUP,FALLING);
  Serial.begin(9600);
}

void loop() 
{
  AngVel = angvel();
  
  if(!digitalRead(reset))
  {
    count = 0;
  }
  
  else
  {
    
  }
  Serial.print("Counter value is : ");
  Serial.print(count);
  Serial.print('\t');
  Serial.print("Angular Velocity is : ");
  Serial.println(AngVel);
  delay(100);
}
