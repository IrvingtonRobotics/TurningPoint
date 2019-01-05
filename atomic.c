
void drive(int leftPow, int rightPow) {
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

void flywheel(int speed) {
	motor[flywheelLeft] = speed;
	motor[flywheelRight] = speed;
}

void moveClaw(int speed) {
	motor[clawFlip] = speed;
}

int clawPosition() {
	return SensorValue[clawPot];
}

int liftBottomPosition() {
	return min(SensorValue[liftLeftPot], SensorValue[liftRightPot]);
}

int leftTopPosition() {
	return max(SensorValue[liftLeftPot], SensorValue[liftRightPot]);
}

int liftPosition() {
	return (SensorValue[liftLeftPot] + SensorValue[liftRightPot]) / 2;
}
