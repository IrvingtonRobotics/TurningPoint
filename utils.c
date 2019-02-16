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

int bezier(int t, int p1, int p2, int p3, int p4) {
	return 127*bezier(t/127.0, p1/127.0, p2/127.0, p3/127.0, p4/127.0);
}

float bezier(float t, float p1, float p2, float p3, float p4) {
	// p1 and p4 are endpoints, p2 and p3 are corresponding control points
	float m = 1 - t;
	// eh
	return m*(m*(m*p1 + t*p2) + t*t*p3) + t*t*t*p4;
}
