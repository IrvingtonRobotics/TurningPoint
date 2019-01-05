// drive

void doDrive() {
	// two joysticks
	int leftSpeed = deDead(leftDriveJoystick);
	int rightSpeed = deDead(rightDriveJoystick);
	moveDrive(leftSpeed, rightSpeed);
}

// conveyor

void doConveyor() {
	if (conveyorUpButton) {
		moveConveyor(127);
		} else if (conveyorDownButton) {
		moveConveyor(-127);
		} else {
		moveConveyor(0);
	}
}

// flywheel

void doFlywheel() {
	if (flywheelButton) {
		moveFlywheel(127);
		} else {
		moveFlywheel(0);
	}
}

// arm

void doArms() {
	int speed = deDead(armJoystick);
	moveArms(speed);
}

// claw

bool lastClawButtonValue = false;
bool clawFlipped = true;
int clawDir = 0;

void doClaw() {
	// for flipping 180
	bool currentClawButtonValue = clawButton ? true : false;
	if (currentClawButtonValue && !lastClawButtonValue) {
		flipClaw();
	}
	lastClawButtonValue = currentClawButtonValue;
}
