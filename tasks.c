#include "utils.c"
#include "atomic.c"

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
