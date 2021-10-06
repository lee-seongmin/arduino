byte echoPin = 13;
byte trigPin = 12;
float dist;

float measure()
{
  digitalWrite(trigPin,LOW);digitalWrite(echoPin,LOW);//clear
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW); 
  //echoPin이 HIGH를 유지한 시간을 저장한다.
  unsigned long duration = pulseIn(echoPin,HIGH);
  //HIGH 였을 때 시간(초음파가 보냈다가 다시 돌아오는 시간)을 가지고 거리를 계산한다.
  float distance = ((float)(340*duration) / 10000) / 2;
  return distance;
}
void setup() {
  Serial.begin(9600);
  //trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  dist = measure();
  Serial.print(dist);
  Serial.println("cm");
  delay(500);
}
