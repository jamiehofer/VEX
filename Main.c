//this is my edit example
#pragma config(Sensor, dgtl1,  Pneumatic1,     sensorDigitalOut)
#pragma config(Sensor, dgtl2,  Pneumatic2,     sensorDigitalOut)
#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightFront,    tmotorVex393_HBridge, openLoop)
#pragma platform(VEX2)
#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

void setLeft(int speed) {
    motor[leftFront] = speed;
    motor[leftBack] = speed;
}

void setRight(int speed) {
    motor[rightFront] = speed;
    motor[rightBack] = speed;
}

void setAll(int speed) {
    setLeft(speed);
    setRight(speed);
}

void forward (int time, int mspeed){
	playSound(soundFastUpwardTones);
    setAll(-mspeed);
    delay(time);
    setAll(0);
}

void turnl (int time, int dif) { 
	playSound(soundBlip);
    setLeft(-127 - dif);
    setRight(-127);
    delay(time);
    setAll(0);
}

void turnr (int time, int dif) {
    playSound(soundBeepBeep);
    setRight(-127 + dif);
    setLeft(-127);
    delay(time);
    setAll(0);
}

void pre_auton(){
	bStopTasksBetweenModes = true;
}
//to turn left use a 0 and to turn right use a 1
task autonomous(){
	forward(1000, 127); //calling the drive forward function with a time of 1000 and a speed of 127
	turnl(1000, 50); //turning left with a diff of speed of 45
}

task usercontrol(){
	while(true){
		//all *-1 are because of the orientation of the motors
		motor[leftFront] = vexRT[Ch3]*-1;
		motor[leftBack] = vexRT[Ch3];
		motor[rightFront] = vexRT[Ch2]*-1;
		motor[rightBack] = vexRT [Ch2]*-1;
	    	SensorValue[Pneumatic1] = vexRT[Btn7U];
		SensorValue[Pneumatic2] = vexRT[Btn7U];
		}
}
