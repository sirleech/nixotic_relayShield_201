// Test: SRS-002
// Interface: Digital 5v
// Description: Turn on and off relay 1 and 2
// Success Criteria: A switched voltage is detected when relay is on
// Notes: 	- Log failures to serial port
//		- Green and red leds
//		- Green = passing
//		- Red = failure"

int count = 1;

void setup()
{
	pinMode(2,OUTPUT); //relay A control
	pinMode(3,OUTPUT); //relay B control
	pinMode(4,INPUT);  //relay A 5v test
	pinMode(5,INPUT);  //relay B 5v test
	Serial.begin(9600);
}

void loop()
{
	Serial.print("Test #");
	Serial.print(count++); newline();
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
	Serial.print("relay A on, test state=");
	Serial.print(relay_A_state());
	newline();
}
int relay_A_state(){
	return digitalRead(4);
}
void turnOffRelay_A() {
        digitalWrite(2,LOW);
	Serial.print("relay A off, test state=");
	Serial.print(relay_A_state());
        newline();
}
void turnOnRelay_B() {
        digitalWrite(3,HIGH);
	Serial.print("relay B on, test state=");
	Serial.print(relay_B_state());
	newline();
}
int relay_B_state(){
        return digitalRead(5);
}
void turnOffRelay_B() {
        digitalWrite(3,LOW);
	Serial.print("relay B off, test state=");
	Serial.print(relay_B_state());
        newline();
}
void newline(){
	Serial.println("");
}
