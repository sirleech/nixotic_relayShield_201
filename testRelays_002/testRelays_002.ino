// Test: SRS-002
// Interface: Digital 5v
// Description: Turn on and off relay 1 and 2
// Success Criteria: A switched voltage is detected when relay is on
// Notes: 	- Log failures to serial port
//		- Green and red leds
//		- Green = passing
//		- Red = failure"

int count = 1;

#define relayPinA 2
#define relayPinB 3
#define relayPinA_test 4
#define relayPinB_test 5 

void setup()
{
	pinMode(relayPinA,OUTPUT); //relay A control
	pinMode(relayPinB,OUTPUT); //relay B control
	pinMode(relayPinA_test,INPUT);  //relay A 5v test
	pinMode(relayPinB_test,INPUT);  //relay B 5v test
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
	digitalWrite(relayPinA,HIGH);
	Serial.print("relay A on, test state=");
	Serial.print(relay_A_state());
	newline();
}
int relay_A_state(){
	return digitalRead(relayPinA_test);
}
void turnOffRelay_A() {
        digitalWrite(relayPinA,LOW);
	Serial.print("relay A off, test state=");
	Serial.print(relay_A_state());
        newline();
}
void turnOnRelay_B() {
        digitalWrite(relayPinB,HIGH);
	Serial.print("relay B on, test state=");
	Serial.print(relay_B_state());
	newline();
}
int relay_B_state(){
        return digitalRead(relayPinB_test);
}
void turnOffRelay_B() {
        digitalWrite(relayPinB,LOW);
	Serial.print("relay B off, test state=");
	Serial.print(relay_B_state());
        newline();
}
void newline(){
	Serial.println("");
}
