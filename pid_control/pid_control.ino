const byte pinCLK = 2, pinDT = 3, m1=5, m2=6;
const float DELAY_TIME=80, PULSE_REV=26, RATIO=30, RPM=60, pi=3.14;

float AngVel;
volatile int count = 0;
const float Kp=1.0, Ki=10.0, Kd=0.01; //PID Gain, 18:1
unsigned long oldt=0, tim=0;
float Setpoint, Input, Output, olderror=0, oldintegral=0;

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

//Computation of the PID output
float PID(float Setpoint, float Input) //Input=y(t)현재의 속도
{
  float newerror = Setpoint-Input; //
  unsigned long newt = millis();
  unsigned long dt = newt-oldt; //in milliseconds
  float newintegral = oldintegral + newerror * dt / 1000;
  float derivative = ((newerror-olderror) / dt) * 1000;
  float iterm0=Ki * newintegral;
  float iterm = constrain(iterm0,-200.0,200.0); 
  // To apply the integral-windup pseudo-protection 
  // 일반적으로 i항이 젤 크다. 500이 넘어가도 범위를 제한해준다.
  float Output = Kp * newerror + iterm + Kd * derivative;
  olderror = newerror; oldintegral=newintegral; oldt=newt;
  return Output;
}

void print1()
{
  Serial.print(Input);
  Serial.print(',');
  Serial.println(Setpoint);
  return;
}

void setup() 
{
  pinMode(pinCLK, INPUT_PULLUP); 
  pinMode(pinDT, INPUT_PULLUP);
  attachInterrupt(0, valueUP, CHANGE);
  Serial.begin(38400); 
}

void loop() 
{
  signed int Output1, Output11;
  Setpoint=140; // [rpm]
  Input=angvel();
  Output1=PID(Setpoint,Input); 
  Output11=constrain(Output1,-255,255);
  if (Output11>0)
  {
    analogWrite(m1,Output11);
    analogWrite(m2,0);
  }
  else 
  {
    analogWrite(m1,0);
    analogWrite(m2,abs(Output11));
  }
  print1();
}
