#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int maxArea(int* height, int heightSize) {
	int nMax = 0, nL = 0, nR = heightSize - 1, nCurrent=0;

	while (nL < nR) {

		nCurrent = (height[nL] <= height[nR]) ? height[nL] * (nR - nL) : height[nR] * (nR - nL);

		nMax = nCurrent > nMax ? nCurrent : nMax;

		if (height[nL] <= height[nR]) {
			nL++;
		}
		else {
			nR--;
		}
	}

	return nMax;
}


int maxAreaSecond(int* height, int heightSize) {
	int nMax = 0, nL = 0, nR = heightSize - 1;

	while (nL < nR) {
		nMax = MAX(nMax, MIN(height[nL], height[nR])*(nR - nL));
		if (height[nL] <= height[nR]) {
			nL++;
		}
		else {
			nR--;
		}
	}

	return nMax;
}

int maxAreaThird(int* height, int heightSize) {
	int nMax = 0;

	for (int i = 0; i < (heightSize - 1); i++) {
		for (int j = i + 1; j < heightSize; j++) {
			nMax = MAX(nMax, MIN(height[i], height[j])*(j - i));
		}
	}
	return nMax;
}