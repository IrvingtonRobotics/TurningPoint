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
	} else {
		stopFlywheel();
	}
}

// flipper

void doFlipper() {
	if (flipperButton) {
		moveFlipper(127);
	} else if (flipperIntakeButton) {
		moveFlipper(-127);
	} else {
		moveFlipper(0);
	}
}
