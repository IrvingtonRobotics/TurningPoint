#include "utils.c"
#include "atomic.c"
// configs
// make sure A is less than about 1200
#define clawPosA 750
#define clawPosB (clawPosA + 2782)

int clawTarget = clawPosA;

task clawController() {
	while(true) {
		int error = clawTarget - clawPosition();
		// adjust multiplier as kP (proportionality coefficient)
		int motorPower = error / 7;
		motorPower = bound(motorPower, 127);
		motorPower = deDead(motorPower);
		moveClaw(motorPower);
		wait1Msec(10);
	}
}

// for driving straight
int driveClicksLeft = 0;
int leftDriveSpeed = 0;
int rightDriveSpeed = 0;

task driveController() {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while(true) {
		/*if (driveClicksLeft > 0) {
			int left = -SensorValue[leftEncoder];
			int right = -SensorValue[rightEncoder];
			int error = right - left;
			rightDriveSpeed += error / 10;
			driveClicksLeft -= 10;
			//driveClicksLeft -= abs(right);
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
		}*/
		drive(leftDriveSpeed, rightDriveSpeed);
		wait1Msec(10);
	}
}

int flywheelSpeed = 0;
int targetFlywheelSpeed = 0;
task flywheelController() {
	while (true) {
		flywheelSpeed += sgn(targetFlywheelSpeed - flywheelSpeed);
		flywheel(flywheelSpeed);
		wait1Msec(10);
	}
}

void moveFlywheel(int speed) {
	targetFlywheelSpeed = speed;
}

void startAllTasks() {
	startTask(clawController);
	startTask(driveController);
	startTask(flywheelController);
}

void moveDrive(int left, int right) {
	leftDriveSpeed = left;
	rightDriveSpeed = right;
}

void driveStraight(int speed, int distance) {
	// distance in inches
	// where's copysign?
	speed = sgn(distance) * abs(speed);
	moveDrive(speed, speed);
	driveClicksLeft = abs(distance) * 28;
}
