#include "utils.c"
#include "atomic.c"


// for driving straight
#define driveClicksPerInch 20
#define driveClicksTolerance (driveClicksPerInch * 2)
#define pRegion (driveClicksPerInch * 5)
int leftDriveClicks = 0;
int rightDriveClicks = 0;
int leftDriveSpeed = 0;
int rightDriveSpeed = 0;

void resetDriveEncoders() {
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
}

int getDLeft() {
	int dLeft = leftDriveClicks - getLeftDriveEncoder();
	return deDead(dLeft, driveClicksTolerance);
}

int getDRight() {
	int dRight = rightDriveClicks - getRightDriveEncoder();
	return deDead(dRight, driveClicksTolerance);
}

bool isEncoderDrive() {
	int dLeft = getDLeft();
	int dRight = getDRight();
	return (dLeft != 0 || dRight != 0);
}

int getDriveSpeed(int diff, int fullSpeed) {
	if (abs(diff) < driveClicksTolerance) {
		return 0;
	} else if (abs(diff) < pRegion) {
		return abs(fullSpeed) * diff / pRegion;
	} else {
		return sgn(diff) * abs(fullSpeed);
	}
}

task driveController() {
	resetDriveEncoders();
	while(true) {
		int dLeft = getDLeft();
		int dRight = getDRight();
		if (isEncoderDrive()) {
			int leftSpeed = getDriveSpeed(dLeft, leftDriveSpeed);
			int rightSpeed = getDriveSpeed(dRight, rightDriveSpeed);
			drive(leftSpeed, rightSpeed);
		} else {
			drive(leftDriveSpeed, rightDriveSpeed);
		}
		wait1Msec(10);
	}
}

int flywheelSpeed = 0;
int targetFlywheelSpeed = 0;
task flywheelController() {
	while (true) {
		flywheelSpeed += sgn(targetFlywheelSpeed - flywheelSpeed);
		flywheelSpeed = bound(flywheelSpeed, 0, 127);
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
