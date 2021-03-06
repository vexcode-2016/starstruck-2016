#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    knob,           sensorNone)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           DLF,           tmotorVex393TurboSpeed_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           DRF,           tmotorVex393TurboSpeed_MC29, PIDControl, reversed, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port3,           DRB,           tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port4,           DLB,           tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port5,           AL1,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           AR1,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           AR2,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           AL2,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           AL0,           tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port10,          AR0,           tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"



void stopMotors()
{
	motor[DLF] = -5;
	motor[DLB] = -5;
	motor[DRF] = -5;
	motor[DRB] = -5;
	wait10Msec(1);
	motor[DLF] = 0;
	motor[DLB] = 0;
	motor[DRF] = 0;
	motor[DRB] = 0;
}

void moveForward(float rotations)
{
	nMotorEncoder[DRF] = 0;
	while(nMotorEncoder[DRF]<rotations*360)
	{
		motor[DLF] = 105;
		motor[DLB] = 105;
		motor[DRF] = 127;
		motor[DRB] = 127;
	}
	stopMotors();



}

task drive() //drive train controler comands
{
	motor[DLF] = vexRT[Ch3]/2;
	motor[DLB] = vexRT[Ch3]/2;
	motor[DRF] = vexRT[Ch2]/2;
	motor[DRB] = vexRT[Ch2]/2;
}

task arm()//arm controler comands: raise arm
{
	while(1)
	{
		if (vexRT[Btn6U] == 1)
		{
			motor[AL1] = 127;
			motor[AL2] = 127;
			motor[AR1] = 127;
			motor[AR2] = 127;
			motor[AR0] = 127;
			motor[AL0] = 127;
		}
		else if (vexRT[Btn5U] == 1)//arm controler commands: drop arm
		{
			motor[AL1] = -127;
			motor[AL2] = -127;
			motor[AR1] = -127;
			motor[AR2] = -127;
			motor[AR0] = -127;
			motor[AL0] = -127;
		}
		else
		{
			motor[AL1] = 0;
			motor[AL2] = 0;
			motor[AR1] = 0;
			motor[AR2] = 0;
			motor[AR0] = 0;
			motor[AL0] = 0;
		}
	}
}





/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	/*
  wait1Msec(2000);

  int lowerarm; //Varables
  int armhit;
  int distance;
  lowerarm = 720;
  armhit = 400;
  distance = 650;

  moveForward(1.1);
  stopMotors();
  wait1Msec(2000);
  while(SensorValue[I2C_2] < armhit)
 {
			motor[AL1] = -127;
			motor[AL2] = -127;
			motor[AR1] = -127;
			motor[AR2] = -127;
			motor[AR0] = -127;
			motor[AL0] = -127;

		}
	stopMotors();*/
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{


  // User control code here, inside the loop
	while(1)
	{
		startTask (drive);
		startTask (arm);

	}
}
