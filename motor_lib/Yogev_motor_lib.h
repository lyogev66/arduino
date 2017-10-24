#ifndef YOGEV_MOTOR_LIB_H
#define YOGEV_MOTOR_LIB_H

#include "Arduino.h"

class YogevMotor
{
	public:
		YogevMotor(
			int enableA,int pinA1,int pinA2,
			int enableB,int pinB1,int pinB2
			);
		//motor functions
		void motorAforward();
		void motorBforward();
		void motorAbackward();
		void motorBbackward();
		void motorAstop() ;
		void motorBstop() ;
		void motorAcoast();
		void motorBcoast();
		void motorAon();
		void motorBon();
		void motorAoff();
		void motorBoff();

		// Movement functions

		void forward (int duration);
		void backward (int duration);
		void left (int duration);
		void right (int duration);
		void coast (int duration);
		void breakRobot (int duration);
		void disableMotors ();
		void enableMotors ();

	private:
		//Motor A
			int _enableA;
			int _pinA1;
			int _pinA2;
		//Motor B			
			int _enableB;
			int _pinB1;
			int _pinB2;
		//define time for run
		// in milliseconds
			int _running;
};

#endif
