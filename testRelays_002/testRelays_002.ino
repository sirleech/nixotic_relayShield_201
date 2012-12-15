// Test: SRS-002
// Interface: Digital 5v
// Description: Turn on and off relay 1 and 2
// Success Criteria: A switched voltage is detected when relay is on
// Notes: 	- Log failures to serial port

int count = 1;
int successCount = 0;
int failCount = 0;

#define delay_ms 100

#define iterations 20

#define relayPinA 3
#define relayPinB 2
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
	if(count <= iterations)
	{
		Serial.print("Iteration #");
        	Serial.print(count++);
        	Serial.print(", Successes: ");
        	Serial.print(successCount);
        	Serial.print(", Failures: ");
        	Serial.print(failCount);
        	newline();

		turnOnRelay_A();
		turnOffRelay_A();

		turnOnRelay_B();
		turnOffRelay_B();
		hr();
	}

}

void turnOnRelay_A() {
	digitalWrite(relayPinA,HIGH);
	delay(delay_ms);
	Serial.print("relay A on, test state=");
	int state = relay_A_state();
	Serial.print(state);
	assert(state == 1);
	newline();
}
int relay_A_state(){
	return digitalRead(relayPinA_test);
}
void turnOffRelay_A() {
        digitalWrite(relayPinA,LOW);
	delay(delay_ms);
	Serial.print("relay A off, test state=");
	int state = relay_A_state();
	Serial.print(state);
	assert(state == 0);
        newline();
}
void turnOnRelay_B() {
        digitalWrite(relayPinB,HIGH);
	delay(delay_ms);
	Serial.print("relay B on, test state=");
	int state = relay_B_state();
	Serial.print(state);
	assert(state == 1);
	newline();
}
int relay_B_state(){
        return digitalRead(relayPinB_test);
}
void turnOffRelay_B() {
        digitalWrite(relayPinB,LOW);
	delay(delay_ms);
	Serial.print("relay B off, test state=");
	int state = relay_B_state();
	Serial.print(state);
	assert(state == 0);
        newline();
}
void newline(){
	Serial.println("");
}
void hr(){
	Serial.println("============================");
}
void assert(boolean condition) {
	if(condition)
                successCount ++;
        else
                failCount ++;
}
