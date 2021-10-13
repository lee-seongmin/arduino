#include <SPI.h>     // Slave of SPI

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(MISO, OUTPUT);       
  pinMode(MOSI, INPUT); 
  pinMode(SCK, INPUT);            
  pinMode(SS, INPUT); SPCR |= _BV(SPE);                 
  SPCR &= ~_BV(MSTR); SPCR |= _BV(SPIE); 
  SPI.attachInterrupt(); 
}

ISR (SPI_STC_vect) 
{ 
  int data; 
  if (Serial.available()) 
  { 
    data = Serial.read(); 
    SPDR = data; 
  } 
  else 
  { 
    data = SPDR;
    SPDR = NULL; 
    if (data != NULL) 
      Serial.write(data); 
  } 
}

void loop ()
{
  delay(100); 
}
