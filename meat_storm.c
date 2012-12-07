#pragma config(Sensor, dgtl1,  leftTowerEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  Button1,        sensorTouch)
#pragma config(Sensor, dgtl6,  Button2,        sensorTouch)
#pragma config(Sensor, dgtl7,  Button3,        sensorTouch)
#pragma config(Sensor, dgtl8,  Button4,        sensorTouch)
#pragma config(Motor,  port2,           leftWheel,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightTower,    tmotorVex393, openLoop)
#pragma config(Motor,  port5,           leftTower,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           intake,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           rightWheel,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

#include "autonomous.c" // Low-level movement methods for autonomous

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop
	float threshold = 12.7;

	while (true)
	{

	  if (abs(vexRT[Ch3]) > threshold)
	  {
	  	motor[leftWheel] = vexRT[Ch3];
		}
		else
		{
				motor[leftWheel] = 0;
		}
		if (abs(vexRT[Ch2]) > threshold)
		{
			motor[rightWheel] = vexRT[Ch2];
		}
		else
		{
			motor[leftWheel] = 0;
			motor[rightWheel] = 0;
		}

		if (vexRT[Btn6U] == 1)
		{
			motor[rightTower] = 90;
			motor[leftTower] = 90;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[rightTower] = -90;
			motor[leftTower] = -90;
		}
		else
		{
			motor[rightTower] = 0;
			motor[leftTower] = 0;
		}
	} // end while loop

} // end usercontrol task
