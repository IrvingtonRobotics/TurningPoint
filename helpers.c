void rotateInPlace(int speed) {
	/* positive speed: turn right
	* negative speed: turn left
	*/
	moveDrive(speed, -speed);
}

void stopDriving() {
	moveDrive(0, 0);
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

#define HIGH_FLAG 3
#define MIDDLE_FLAG 2
int flywheelFlag = HIGH_FLAG;

int topSpeeds[] = {60, 70, 90, 110};
int middleSpeeds[] = {50, 60, 80, 100};

void runFlywheel(int distanceFromBase) {
	int speed;
	if (flywheelFlag == HIGH_FLAG) {
		speed = topSpeeds[distanceFromBase];
	} else {
		speed = middleSpeeds[distanceFromBase];
	}
	moveFlywheel(speed);
}

void stopFlywheel() {
	moveFlywheel(0);
}

void flipClaw() {
	int pos = clawPosition();
	if (abs(pos - clawPosA) < abs(pos - clawPosB)) {
		clawTarget = clawPosB;
		} else {
		clawTarget = clawPosA;
	}
}
