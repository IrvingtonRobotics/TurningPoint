// drive

void doDrive() {
	// two joysticks
	if (!isEncoderDrive()) {
		int leftSpeed = deDead(leftDriveJoystick);
		int rightSpeed = deDead(rightDriveJoystick);
		moveDrive(leftSpeed, rightSpeed);
	}
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
	} else if (flywheelFullSpeedButton) {
		moveFlywheelInstant(127);
	} else {
		stopFlywheel();
	}
}

// flipper
int flipperDirection = 0;
#define flipperSpeed 127
void doFlipper() {
	if (flipperButton) {
		flipperDirection = flipperDirection ? 0: 1;
	} else if (flipperIntakeButton) {
		flipperDirection = flipperDirection ? 0 : -1;
	}
	moveFlipper(flipperDirection * flipperSpeed);
}
