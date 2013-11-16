#pragma config(Hubs,  S1, MatrxRbtcs, none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     colorport,      sensorCOLORRED)
#pragma config(Motor,  mtr_Matrix_S1_1, motorE,        tmotorMatrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_Matrix_S1_2, motorD,        tmotorMatrix, openLoop, encoder)
#pragma config(Motor,  mtr_Matrix_S1_3, motorF,        tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_Matrix_S1_4, motorG,        tmotorMatrix, openLoop)
#pragma config(Servo,  srvo_Matrix_S1_1, servo1,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_2, servo2,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_3, servo3,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_4, servo4,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an Tetrix robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void followTheLineFor3Turns();
void moveTillWhiteLine();
//void testEncoder();
//void testColor();
void turnLeftTillLine();
void moveForward();
void reverse();

int colorMid =0;
int sColor =6;
string disp;
bool move = true;



/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{

  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

int black;
wait10Msec(200);
black=SensorValue[colorport];
wait10Msec(50);
black=SensorValue[colorport];
colorMid=(black+(black/2));
StringFormat(disp,"%d %d", black, colorMid);
nxtDisplayCenteredTextLine(2, disp );

	//PlayTone(850, 100);
	//int white;
	//white= SensorValue[colorport];
	//wait10Msec(200);
	//white= SensorValue[colorport];
 // StringFormat(disp,"White is %d", white);
 // nxtDisplayCenteredTextLine(2, disp );
	//wait10Msec(200);

	//PlayTone(800, 100);
	//wait10Msec(200);
	//int black= SensorValue[colorport];
 // StringFormat(disp,"Black is %d", black);
 // nxtDisplayCenteredTextLine(2, disp );
	//wait10Msec(200);

	//colorMid = (white+black)/2;
 // StringFormat(disp,"Mid is %d", colorMid);
 // nxtDisplayCenteredTextLine(2, disp );
	//PlayTone(750, 100);
	//wait10Msec(500);

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();
	//testColor();
	//testEncoder();


  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    CyberFacons Code Begins  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////


	//waitForStart(); // Wait for the beginning of autonomous phase.

	moveTillWhiteLine();
	moveForward();
	turnLeftTillLine();
	reverse();
	followTheLineFor3Turns();

	// ================= CyberFalcon Code end ============
	while (true)
  {}
}


// what does this do?
void moveForward(){
	motor[motorD]= 100;
	motor[motorE]= 100;
	wait1Msec(250);
	motor[motorD]= 0;
	motor[motorE]= 0;
}

void reverse(){
	motor[motorD]= -50;
	motor[motorE]= -50;
	wait1Msec(100);
	motor[motorD]= 0;
	motor[motorE]= 0;
	wait1Msec(200);
}



void followTheLineFor3Turns(){
 bool move= true;
 nMotorEncoder[motorE] = 0;
 while (move) {
       motor[motorD] = 100;
       motor[motorE] = 100;
   if (nMotorEncoder[motorE] > 4200) move = false;
 }
       motor[motorE] = 0;
       motor[motorD] = 0;

}





//void followTheLineFor3Turns()
//{
// string disp;
// bool move = true;

// nMotorEncoder[motorE] = 0;
// while (move) {
//   sColor = SensorValue[colorport];
//   //StringFormat(disp,"%d", sColor);
//   //nxtDisplayCenteredTextLine(2, disp );
//   if (sColor > colorMid)
//     {
//       motor[motorD] = 90;
//       motor[motorE] = 70;
//     }
//     else
//     {
//       motor[motorE] = 90;
//       motor[motorD] = 70;
//     }
//   if (nMotorEncoder[motorE] > 3500) move = false;
// }
//       motor[motorE] = 0;
//       motor[motorD] = 0;

//}


void turnLeftTillLine(){
	move=true;
	while(move)
			{
				motor[motorD] = 0;
				motor[motorE] = 30;
				sColor = SensorValue[colorport];
				if (sColor > colorMid) move = false;
			  StringFormat(disp,"%d", sColor);
			  nxtDisplayCenteredTextLine(2, disp );
			  }
				// move in opposite direction to be back on the line
				motor[motorD] = 0;
				motor[motorE] = 0;
				wait10Msec(100);
}


void moveTillWhiteLine(){
	move=true;
	motor[motorD] = 40;
	motor[motorE] = 40;
	while(move)
				{
   			sColor = SensorValue[colorport];
   			StringFormat(disp,"%d %d", sColor, colorMid);
   			nxtDisplayCenteredTextLine(2, disp );
				if (sColor > colorMid) {move = false;}
			  }
	motor[motorD] = 0;
	motor[motorE] = 0;

}

void testEncoder(){
   nMotorEncoder[motorD] = 0;
   int motorCount = 0;
		motor[motorD] = 20;
		motor[motorE] = 20;
  	while(1){
  		motorCount = nMotorEncoder[motorD];
  		StringFormat(disp,"sensor count %d", motorCount);
   		nxtDisplayCenteredTextLine(2, disp );
		}
}


void testColor(){
	motor[motorD] = 40;
	motor[motorE] = 40;
	while(1){
   sColor = SensorValue[colorport];
   StringFormat(disp,"%d", sColor);
   nxtDisplayCenteredTextLine(2, disp );
 }
 }
