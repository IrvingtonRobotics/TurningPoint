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
	if (highFlagButton) {
		flywheelFlag = HIGH_FLAG;
	} else if (middleFlagButton) {
		flywheelFlag = MIDDLE_FLAG;
	}
	if (distance1Button) {
		runFlywheel(1);
	} else if (distance2Button) {
		runFlywheel(2);
	} else if (distance3Button) {
		runFlywheel(3);
	} else if (distance4Button) {
		runFlywheel(4);
	} else {
		stopFlywheel();
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
