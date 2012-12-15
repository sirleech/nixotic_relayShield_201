// Test: SRS-001
// Interface: Digital 5v
// Description: Basic functions, logging

void setup()
{
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	turnOnRelay_A();
	delay(600);
	turnOnRelay_B();
	delay(1200);

	turnOffRelay_A();
	delay(600);
	turnOffRelay_B();
	delay(1200);
}

void turnOnRelay_A() {
	digitalWrite(2,HIGH);
	log("relay A on");
}
void turnOffRelay_A() {
        digitalWrite(2,LOW);
	log("relay A off");
}
void turnOnRelay_B() {
        digitalWrite(3,HIGH);
	log("relay B on");
}
void turnOffRelay_B() {
        digitalWrite(3,LOW);
	log("relay B off");
}
void log(String message){
	Serial.println(message);
}
