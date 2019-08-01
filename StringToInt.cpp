#include <limits.h>
#include <stdlib.h>



int myAtoi(char * str) {
    int nSum = 0, nTemp;
    int nSign = 1, nIdx = 0;

    if (str == NULL)
        return 0;

    while (str[nIdx] == ' ') nIdx++;
    if (str[nIdx] == '+'){
        nIdx++;
    }
    else if(str[nIdx] == '-'){
        nSign = -1;
        nIdx++;
    }
    while (str[nIdx] != '\0'){
        if (str[nIdx] < '0' || str[nIdx] > '9') break;
        nTemp = str[nIdx++] - '0';

        if (nSum > (INT_MAX - nTemp)/10) return nSign > 0? INT_MAX:INT_MIN;

        nSum = nSum*10 + nTemp;
    }
    
    return nSign * nSum;
}


bool safeAdd(int a, int b) {
	if (a >= 0) {
		if (b > INT_MAX - a)
			return false;
	}
	else {
		if (b < INT_MIN - a)
			return false;
	}
	return true;
}

int myAtoiSecond(char * str) {
	int nIdx = 0;
	bool bNeg = false;
	int nSum = 0;
	if (str == NULL)
		return 0;
	while (str[nIdx] == ' ') nIdx++;
	if (str[nIdx] == '+') {
		nIdx++;
	}
	else if (str[nIdx] == '-') {
		bNeg = true;
		nIdx++;
	}
	else if (str[nIdx]<'0' || str[nIdx] > '9') {
		return 0;
	}

	while (str[nIdx]<'9' && str[nIdx]>'0') {
		if (nSum > INT_MAX / 10) {
			return bNeg? INT_MIN:INT_MAX;
		}
		if (!safeAdd(nSum * 10, (str[nIdx] - '0')))
			return bNeg ? INT_MIN : INT_MAX;
		nSum = nSum * 10 + (str[nIdx++] - '0');

	}
	return bNeg? -nSum:nSum;
}