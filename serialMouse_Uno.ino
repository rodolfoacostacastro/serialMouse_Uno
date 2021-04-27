// SerialMouse sketch
#define potXPin 0
#define potYPin 1

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int x = (512 - analogRead(potXPin)) / 4;// range is -127 to +127
  int y = (512 - analogRead(potYPin)) / 4;
  Serial.print(x,DEC);
  Serial.print(",");
  Serial.print(y,DEC);
  Serial.println();  // send a cr/lf
  delay(50); // send position 20 times a second
}
