#include <Arduino.h>

#define inpin 0
#define outpin 10

int val;
float u;
float e;
float pre_e = 0;

void setup()
{
  pinMode(inpin, INPUT);
  pinMode(outpin, OUTPUT);
  TCCR1B = 1;
}

void loop()
{
  val = analogRead(inpin);
  pre_e = e;
  e = 200 - val;
  u = 3 * (e + 6 * (e - pre_e));
  if (u > 255)
    u = 255;
  if (u < 0)
    u = 0;
  analogWrite(outpin, u);

  delayMicroseconds(300);
}