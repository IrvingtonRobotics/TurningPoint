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

void flipClaw() {
	int pos = clawPosition();
	if (abs(pos - clawPosA) < abs(pos - clawPosB)) {
		clawTarget = clawPosB;
		} else {
		clawTarget = clawPosA;
	}
}
