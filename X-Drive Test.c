#pragma config(Motor,  port1,           rDriveFront,   tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rDriveBack,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lDriveBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          lDriveFront,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*

*/
task main()
{
	int LY = 0;
	int LX = 0;
	int RY = 0;
	int RX = 0;
	int threshold = 15;
  while(1)
  {
  	//for deadzones; when the joystick value for an axis is below the threshold, the motors controlled by that joystick will not move in that direction
  	LY = (abs(vexRT[Ch3]) > threshold) ? vexRT[Ch3] : 0;
  	LX = (abs(vexRT[Ch4]) > threshold) ? vexRT[Ch4] : 0;
  	RY = (abs(vexRT[Ch2]) > threshold) ? vexRT[Ch2] : 0;
  	RX = (abs(vexRT[Ch1]) > threshold) ? vexRT[Ch1] : 0;
    motor[lDriveFront] = LY + LX;
  	motor[lDriveBack] = LY - LX;
  	motor[rDriveFront] = RY - RX;
  	motor[rDriveBack] = RY + RX;
  	if(vexRT[Btn5U] == 1)
  	{
  	motor[arm] = 127;
  	}
  	else if(vexRT[Btn5D] == 1)
  	{
  		motor[arm] = -127;
  	}
  	else
  	{
  		motor[arm] = 0;
  	}
  }

}
