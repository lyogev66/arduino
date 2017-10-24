#include <Yogev_motor_lib.h>

int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
int play = 1;
long running = 100000;

char incomingByte;   // for incoming serial data

// creating motor object
YogevMotor my_motor(enA,in1,in2,enB,in3,in4);

void setup(){
  Serial.begin(9600);
}




void loop() {
 my_motor.enableMotors();

 while (play) {
   //Forward for 1,5s
//  Serial.println ("forward...");
//  my_motor.forward (1500);
   if (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();         // say what you got:
        Serial.print("I received: ");
        Serial.println(incomingByte);
        switch (incomingByte){
          case 'F':
          Serial.println ("forward...");
          my_motor.forward (10);
          break;
          case 'B':
          Serial.println ("backward...");
          my_motor.backward (10);
          break;
          case 'R':
          Serial.println ("right...");
          my_motor.right (10);
          break;
          case 'L':
          Serial.println ("left...");
          my_motor.left (10);
          break;
          case 'S':
          Serial.println ("coast...");
          my_motor.coast(10);
          break;
          
        }
   }
   
  ////turn right
  // Serial.println ("right...");
  // my_motor.right (500);
  ////Forward for 1,5s
  // Serial.println ("forward...");
  // my_motor.forward (1500);
  ////turn left
  // Serial.println ("left...");
  // my_motor.left (1000);
  
   //Forward for 1,5s
//   Serial.println ("forward...");
//   my_motor.forward (1500);
  if (millis() > running) {
   play = false;
   Serial.println ("Falsing");
   }
 };

 //disable motors
 my_motor.disableMotors();
}

