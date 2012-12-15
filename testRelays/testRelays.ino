////////////////////////////////
//
// Smart Relay Shield v2
//
// Relay 1 = D2
// Relay 2 = D3
//
////////////////////////////////


void setup()
{
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
}

void loop()
{
	digitalWrite(2,HIGH);
	delay(600);
	digitalWrite(3,HIGH);
	delay(1200);

	digitalWrite(2,LOW);
	delay(600);
	digitalWrite(3,LOW);
	delay(1200);
}
