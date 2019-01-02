#pragma config(Motor,  port1,           flywheelLeft,  tmotorVex393TurboSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           clawFlip,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeftFront, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           driveLeftBack, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           liftBottom,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           liftTop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           driveRightFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           driveRightBack, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           conveyor,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          flywheelRight, tmotorVex393TurboSpeed_HBridge, openLoop)

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

// ---- HELPERS

int deDead(int in, int threshold) {
	// deal with dead zone
	if (abs(in) < threshold) {
		return 0;
	}
	return in;
}

int deDead(int in) {
	return deDead(in, 10);
}

// ---- MOVE: wrappers around atomic movement functions

void moveDrive(int leftPow, int rightPow) {
	/* Positive: move forward;
	 * Negative: move backward
	 **/
	// Move the left side of the robot
	motor[driveLeftFront] = leftPow;
	motor[driveLeftBack] = leftPow;
	// Move the right side of the robot
	motor[driveRightFront] = rightPow;
	motor[driveRightBack] = rightPow;
}

void moveArms(int dir) {
	// move both arms in unison
	motor[liftTop] = dir;
	motor[liftBottom] = dir;
}

void moveConveyor(int speed) {
	// move conveyor
	motor[conveyor] = speed;
}

void moveFlywheel(int speed) {
	motor[flywheelLeft] = speed;
	motor[flywheelRight] = speed;
}

void moveClaw(int speed) {
	motor[clawFlip] = speed;
}

// ---- MOVE: advanced movement (autom helpers)

// drive

void rotateLeftFixed(int speed) {
	moveDrive(0, speed);
}

void rotateRightFixed(int speed) {
	moveDrive(speed, 0);
}

void rotateInPlace(int speed) {
	/* positive speed: turn right
   * negative speed: turn left
	 */
  moveDrive(speed, -speed);
}

void driveStraight(int speed) {
	moveDrive(speed, speed);
}

void stopDriving() {
	moveDrive(0, 0);
}

void waitMS(int millis) {
	wait1Msec(millis);
}

void wait(int seconds) {
	wait1Msec(seconds * 1000);
}

void driveDistance(int distance) {
	// calibrate so distance is in inches (1/24 of tile)
	driveStraight(sgn(distance) * 60);
	// TOCALIBRATE
	waitMS(abs(distance) * 10);
	stopDriving();
}


int angleMultiplier = 1;
void rotateAngle(int angle) {
  // calibrate so angle is in degrees
	// positive --> clockwise
	// TOCALIBRATE
	rotateInPlace(sgn(angle)* 60);
	waitMS(abs(angle) * 10);
	stopDriving();
}

void shoot(int flag, int distanceFromBase) {
	// 3 for top flag, 2 for middle flag
	int dx = distanceFromBase;
	int dy;
	if (flag == 3) {
		dy = 46;
	} else if (flag == 2) {
		dy = 32;
	}
	// TODO: now do some physics and speed curve to determine motor control
}

// ---- DO: observe input and act upon it

// drive

void doDrive() {
	// one-joystick drive on left joystick (ch 3 and 4)
	int y = deDead(vexRT[Ch3]);
	int x = deDead(vexRT[Ch4]);
	int leftSpeed = x + y;
	int rightSpeed = x - y;
	moveDrive(leftSpeed, rightSpeed);
}

// conveyor

void doConveyor() {
	// buttons 6U and 6D move conveyor up and down
	if (vexRT[Btn6U]) {
		moveConveyor(127);
	} else if (vexRT[Btn6D]) {
		moveConveyor(-127);
	} else {
		moveConveyor(0);
	}
}

// flywheel

void doFlywheel() {
	// button 8U runs flywheel
	if (vexRT[Btn8U]) {
		moveFlywheel(127);
	} else {
		moveFlywheel(0);
	}
}

// arm

void doArms() {
	// Right joystick (ch2) controls arms
	int speed = deDead(vexRT[Ch2]);
	moveArms(speed);
}

// claw

bool lastClawButtonValue = false;
bool clawFlipped = true;
int clawDir = 0;

void flipClaw() {
	moveClaw(60);
	// TOCALIBRATE
	waitMS(500);
	moveClaw(0);
}

void doClaw() {
	/* Button 7U to flip the claw 180 deg
	 * Buttons 5U and 5D move claw back and forth
	 */
	// for flipping 180
	bool currentClawButtonValue = vexRT[Btn7U] ? true : false;
	if (currentClawButtonValue && !lastClawButtonValue) {
		flipClaw();
	}
	lastClawButtonValue = currentClawButtonValue;
	// for back and forth
	int clawSpeed = 100;
	if (vexRT[Btn5U]) {
		moveClaw(clawSpeed);
	} else if (vexRT[Btn5D]) {
		moveClaw(-clawSpeed);
	} else {
		moveClaw(0);
	}
}

// ---- MAIN CONTROL

void pre_auton() {
	// stop tasks while changing from autonomous to usercontrol
  bStopTasksBetweenModes = true;
}

task autonomous() {
	// 85 is p much max speed since speed is nonlinear, 60 is reasonable speed
	bool isRed = false;
	// practice as if blue, then negative of drive angles for red
	angleMultiplier = isRed ? -1 : 1;
	// false --> starting position closer to flags
	// true --> starting position closer to posts
	bool startNearFlags = true;
	// completely different routines by sides
	if (startNearFlags) {
		// start at edge of starting tile closer to the flag
		// drive forward then turn to shoot toward high flag
		driveDistance(12);
		rotateAngle(90);
		shoot(3, 30);
		// pick up cap
		rotateAngle(-45);
		driveDistance(20);
		// TODO: lift to pick up the cap
		// drive to pole
		driveDistance(-20);
		rotateAngle(-135);
		driveDistance(24);
		rotateAngle(-90);
		driveDistance(24);
		// TODO: lift the lift
		flipClaw();
	} else {

	}
	angleMultiplier = 1;
}

task usercontrol() {
  while (true) {
		// testing out durations
  	// change the time inside waitMS directly after TOCALIBRATE comments
		if (vexRT[Btn8D]) {
			driveDistance(24);
		}
		if (vexRT[Btn8R]) {
			rotateAngle(360);
		}
		if (vexRT[Btn8L]) {
			flipClaw();
		}
    doDrive();
		doArms();
		doClaw();
		doConveyor();
		doFlywheel();
  }
}
