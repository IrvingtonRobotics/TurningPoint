#include "utils.c"
#include "atomic.c"


// for driving straight
#define driveClicksPerInch 28
#define driveClicksTolerance (driveClicksPerInch / 6)
int leftDriveClicks = 0;
int rightDriveClicks = 0;
int leftDriveSpeed = 0;
int rightDriveSpeed = 0;

void resetDriveEncoders() {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
}

task driveController() {
	resetDriveEncoders();
	while(true) {
		int dLeft = leftDriveClicks - SensorValue[leftEncoder];
		dLeft = deDead(dLeft, driveClicksTolerance);
		int dRight = rightDriveClicks - SensorValue[rightEncoder];
		dRight = deDead(dRight, driveClicksTolerance);
		if (dLeft == 0 && dRight == 0) {
			drive(leftDriveSpeed, rightDriveSpeed);
		} else {
			// will do PID control here; hard stop rn
			int leftSpeed = dLeft == 0 ? 0 : leftDriveSpeed;
			int rightSpeed = dRight == 0 ? 0 : rightDriveSpeed;
			drive(leftSpeed, rightSpeed);
		}
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

void driveDistance(int speed, int leftDist, int rightDist) {
	int maxDist = max(leftDist, rightDist);
	speed = abs(speed);
	int leftSpeed = leftDist / maxDist * speed;
	int rightSpeed = rightDist / maxDist * speed;
	moveDrive(leftSpeed, rightSpeed);
	leftDriveClicks = leftDist * driveClicksPerInch;
	rightDriveClicks = rightDist * driveClicksPerInch;
	resetDriveEncoders();
}

void driveStraight(int speed, int distance) {
	driveDistance(speed, distance, distance);
}
