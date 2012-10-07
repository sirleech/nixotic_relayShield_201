////////////////////////////////
//
// Australian Robotics Smart Relay Shield
//
// Relay 1 = D5
// Relay 2 = D4
// Relay 3 = D3
// Relay 4 = D2
//
////////////////////////////////


unsigned char D[4] = {5,4,3,2};
int ms = 2000;
void setup()
{
  int i;
  for(i = 0; i < 4; i++)
  {
    pinMode(D[i],OUTPUT);
  }
}

void loop()
{
  #if 1
  int i=0;
  for(i = 0; i < 4; i++)
  {
    digitalWrite(D[i],HIGH);
    delay(600);
  }
  delay(ms);
  for(i = 0; i < 4; i++)
  {
    digitalWrite(D[i],LOW);
    delay(600);
  } 
  delay(ms);
  #endif
}
