#pragma config(Hubs,  S1, MatrxRbtcs, none,     none,     none)
#pragma config(Sensor, S2,     touchSense,     sensorTouch)
#pragma config(Motor,  mtr_Matrix_S1_1, motorD,        tmotorMatrix, openLoop, encoder)
#pragma config(Motor,  mtr_Matrix_S1_2, motorE,        tmotorMatrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_Matrix_S1_3, motorF,        tmotorMatrix, openLoop, reversed)
#pragma config(Motor,  mtr_Matrix_S1_4, motorG,        tmotorMatrix, openLoop)
#pragma config(Servo,  srvo_Matrix_S1_1, servo1,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_2, servo2,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_3, servo3,               tServoNone)
#pragma config(Servo,  srvo_Matrix_S1_4, servo4,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

	task main()
	{

	nMotorEncoder[motorD]=0;
	nMotorEncoder[motorE]=0;
	bool runrobot=true;

		while (runrobot) {
				motor[motorD]=100;
				motor[motorE]=100;
				int eEncoder = nMotorEncoder[motorE];
				nxtDisplayTextLine(2, " e val = %d" , eEncoder);
				if (eEncoder > 1440) runrobot=false;
		}
		motor[motorD]=0;
		motor[motorE]=0;

			wait10Msec(100);

		nMotorEncoder[motorD]=0;
		nMotorEncoder[motorE]=0;
		runrobot = true;

		while (runrobot) {
				motor[motorD]=-100;
				motor[motorE]=-100;
				int dEncoder = nMotorEncoder[motorD];
				nxtDisplayTextLine(2, " e val = %d" , dEncoder);
				if (dEncoder < -1440) runrobot=false;
		}

		motor[motorD]=0;
		motor[motorE]=0;

		wait10Msec(500);

		//bool moveArm=true;

		//while (moveArm) {
		//		motor[motorF]=100;
		//		if (SensorValue(touchSense)==1) moveArm=false;
		//}
		//motor[motorF]=0;
		//wait10Msec(200);

		//moveArm=true;
		//while (moveArm) {
		//		motor[motorF]=-100;
		//		if (SensorValue(touchSense)==1) moveArm=false;
		//}
		//motor[motorF]=0;
		//wait10Msec(200);



	int joyValue = 0;
	while(1 == 1)
  {
  	getJoystickSettings(joystick);
  	motor[motorF] = -joystick.joy1_y1;

   // if (joyValue > 15 || joyValue < -15)
   // {
   // 	motor[motorF] = joyValue;
   // }
   // else{
   // 	motor[motorF] = 0;
  	//}
  }






	}
