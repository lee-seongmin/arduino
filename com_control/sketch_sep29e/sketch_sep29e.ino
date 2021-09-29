const byte pinR = 11; //pwm
const byte pinG = 10; //pwm
const byte pinB = 9; //pwm

void setRGB(int r, int g, int b)
{
  analogWrite(pinR, r);
  analogWrite(pinG, g);
  analogWrite(pinB, b);
}

void setup() {
}

void loop() {
  setRGB(255,0,0); //red
  delay(1000);
  setRGB(0,255,0); //green
  delay(1000);
  setRGB(0,0,255); //blue
  delay(1000);
  setRGB(0,0,0);
  delay(1000);
  setRGB(0, 255, 255); //cyan
  delay(1000);
  setRGB(255, 0, 255); //magenta
  delay(1000);
  setRGB(255, 255, 0); //yellow
  delay(1000);
  setRGB(255, 255, 255); //white
  delay(1000);
  setRGB(0, 0, 0);
  delay(1000);
  for (int i=0; i<256; i+=5) {
  setRGB(255-i, i, 0);
  delay(20);
  }
  for (int i=0; i<256; i+=5) {
  setRGB(0, 255-i, i);
  delay(20);
  }
  for (int i=0; i<256; i+=5) {
  setRGB(i, 0, 255-i);
  delay(20);
  }
  setRGB(0, 0, 0);
  delay(1000);
}
