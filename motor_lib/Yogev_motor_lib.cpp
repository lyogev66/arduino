#include "Arduino.h"
#include "Yogev_motor_lib.h"

//constructor
YogevMotor::YogevMotor(
	int enableA,int pinA1,int pinA2,
	int enableB,int pinB1,int pinB2
	)
{
	//configure pin modes
	pinMode (enableA, OUTPUT);
	pinMode (pinA1, OUTPUT);
	pinMode (pinA2, OUTPUT); 

	pinMode (enableB, OUTPUT);
	pinMode (pinB1, OUTPUT);
	pinMode (pinB2, OUTPUT); 

	_enableA = enableA;
	_pinA1 = pinA1;
	_pinA2 = pinA2;

	_enableB = enableB;
	_pinB1 = pinB1;
	_pinB2 = pinB2;

 	_running = 10000; //10 secons
}


//Defining functions so it's more easy
//motor functions
void YogevMotor::motorAforward() {
 digitalWrite (_pinA1, HIGH);
 digitalWrite (_pinA2, LOW);
}
void YogevMotor::motorBforward() {
 digitalWrite (_pinB1, LOW);
 digitalWrite (_pinB2, HIGH);
}
void YogevMotor::motorAbackward() {
 digitalWrite (_pinA1, LOW);
 digitalWrite (_pinA2, HIGH);
}
void YogevMotor::motorBbackward() {
 digitalWrite (_pinB1, HIGH);
 digitalWrite (_pinB2, LOW);
}
void YogevMotor::motorAstop() {
 digitalWrite (_pinA1, HIGH);
 digitalWrite (_pinA2, HIGH);
}
void YogevMotor::motorBstop() {
 digitalWrite (_pinB1, HIGH);
 digitalWrite (_pinB2, HIGH);
}
void YogevMotor::motorAcoast() {
 digitalWrite (_pinA1, LOW);
 digitalWrite (_pinA2, LOW);
}
void YogevMotor::motorBcoast() {
 digitalWrite (_pinB1, LOW);
 digitalWrite (_pinB2, LOW);
}
void YogevMotor::motorAon() {
 digitalWrite (_enableA, HIGH);
}
void YogevMotor::motorBon() {
 digitalWrite (_enableB, HIGH);
}
void YogevMotor::motorAoff() {
 digitalWrite (_enableA, LOW);
}
void YogevMotor::motorBoff() {
 digitalWrite (_enableB, LOW);
}



// Movement functions
void YogevMotor::forward (int duration) {
 motorAforward();
 motorBforward();
 delay (duration);
}
void YogevMotor::backward (int duration) {
 motorAbackward();
 motorBbackward();
 delay (duration);
}
void YogevMotor::left (int duration) {
 motorAbackward();
 motorBforward();
 delay (duration);
}
void YogevMotor::right (int duration) {
 motorAforward();
 motorBbackward();
 delay (duration);
}
void YogevMotor::coast (int duration) {
 motorAcoast();
 motorBcoast();
 delay (duration);
}
void YogevMotor::breakRobot (int duration) {
 motorAstop();
 motorBstop();
 delay (duration);
}
void YogevMotor::disableMotors() {
 motorAoff();
 motorBoff();
}
void YogevMotor::enableMotors() {
 motorAon();
 motorBon();
}
