int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int bound(int in, int min, int max) {
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}
	if (in < min) {
		return min;
		} else if (in > max) {
		return max;
		} else {
		return in;
	}
}

int bound(int in, int absMax) {
	return bound(in, absMax, -absMax);
}

int deDead(int in, int threshold) {
	// deal with dead zone
	if (abs(in) < threshold) {
		return 0;
	}
	return in;
}

int deDead(int in) {
	return deDead(in, 20);
}

void waitMS(int millis) {
	wait1Msec(millis);
}

void wait(int seconds) {
	wait1Msec(seconds * 1000);
}
