////////////////////////////////
//
// Smart Relay Shield v2
//
// Relay 1 = D2
// Relay 2 = D3
//
// Test: Switch on and off the relays
// Output: none
//
////////////////////////////////


unsigned char D[2] = {2,3};
int ms = 2000;
void setup()
{
  int i;
  for(i = 0; i < 2; i++)
  {
    pinMode(D[i],OUTPUT);
  }
}

void loop()
{
  #if 1
  int i=0;
  for(i = 0; i < 2; i++)
  {
    digitalWrite(D[i],HIGH);
    delay(600);
  }
  delay(ms);
  for(i = 0; i < 2; i++)
  {
    digitalWrite(D[i],LOW);
    delay(600);
  } 
  delay(ms);
  #endif
}
