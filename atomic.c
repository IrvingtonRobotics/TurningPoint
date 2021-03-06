void drive(int leftPow, int rightPow) {
	/* Positive: move forward;
	* Negative: move backward
	**/
	// Move the left side of the robot
	motor[driveLeftFront] = leftPow;
	motor[driveLeftMiddle] = leftPow;
	motor[driveLeftBack] = leftPow;
	// Move the right side of the robot
	motor[driveRightFront] = rightPow;
	motor[driveRightMiddle] = rightPow;
	motor[driveRightBack] = rightPow;
}

void moveConveyor(int speed) {
	// move conveyor
	motor[conveyor] = speed;
}

void flywheel(int speed) {
	motor[flywheelLeft] = speed;
	motor[flywheelRight] = speed;
}

void moveFlipper(int speed) {
	motor[flipper] = speed;
}

int rightDriveEncoder() {
	return SensorValue[rightEncoder];
}

int leftDriveEncoder() {
	return SensorValue[leftEncoder];
}
