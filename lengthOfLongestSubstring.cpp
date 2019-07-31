#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int lengthOfLongestSubstring(char * s) {
	bool flags[256] = { false };
	int nStart=0, nEnd=0, nMax = 0;

	while(s[nEnd]!='\0'){
		if (flags[s[nEnd]] == false){
			flags[s[nEnd++]] = true;
			nMax = MAX(nMax, nEnd - nStart);
		}
		else{
			flags[s[nStart++]] = false;
		}
	}
	return nMax;
}

int lengthOfLongestSubstringSecond(char * s) {
	int nStart = 0, nEnd = 0, nMax = 0, nTemp = 0;

	int loc[128];
	memset(loc,-1,128*sizeof(int));

	for (nEnd = 0; nEnd< strlen(s); nEnd++) {
		nTemp = loc[s[nEnd]];
		loc[s[nEnd]] = nEnd;
		if (nTemp >= nStart) {
			nMax = MAX(nMax, nEnd - nStart);
			nStart = nTemp + 1;
		}
	}
	nMax = MAX(nMax, nEnd - nStart);

	return nMax;
}

