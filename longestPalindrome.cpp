//#include <string.h>

//int helperFunc(int nL, int nR, int &nStart, int &nEnd);

#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s) {
	int nMax = 1, nStart = 0, nLen = 0, nCurrentLen;
	int nL = 0, nR = 0;
	char *returnChar = NULL;
	if (!s || s[0]=='\0'){
		return s;
	}
	nLen = strlen(s);
	for (int i = 0; i < nLen && nLen - i > nMax/2; i++){
		nL = i;
		nR = i;
		while(s[nR+1] != '\0' && s[nL] == s[nR+1]) nR++;
		for(;nL >=0&&nR<nLen&&s[nR]==s[nL];--nL,++nR){
			nCurrentLen = nR - nL + 1;
			if (nCurrentLen > nMax){
				nMax = nCurrentLen;
				nStart = nL;
			}
		}
	}
	returnChar = (char *)malloc(sizeof(char)*(nMax + 1));
	strncpy(returnChar, s+nStart, nMax);
	returnChar[nMax] = '\0';
	return returnChar;
}

int helperFunc(int nL, int nR, int *nStart, int *nEnd, char *s){
	if (nL == -1){
		return 0;
	}
    while (nL >= 0 && s[nR] != '\0'){
        if (s[nL] != s[nR]){
            *nStart = ++nL;
            *nEnd = --nR;
			return 0;
        }
        else{
            --nL;
            ++nR;
        }
    }
	*nStart = ++nL;
	*nEnd = --nR;
    return 0;
}

char * longestPalindromeSecond(char * s) {
	int nMiddle = 0, nMax = 0, nStart = 0, nEnd = 0, nSize = 0;
	int returnStart = 0, returnEnd = 0;
	char *returnChar = NULL;

	while (s[nMiddle] != '\0') {
		helperFunc(nMiddle - 1, nMiddle + 1, &nStart, &nEnd, s);
		if (nMax < nEnd - nStart + 1) {
			returnStart = nStart;
			returnEnd = nEnd;
			nMax = nEnd - nStart + 1;
		}
		helperFunc(nMiddle, nMiddle + 1, &nStart, &nEnd, s);
		if (nMax < nEnd - nStart + 1) {
			returnStart = nStart;
			returnEnd = nEnd;
			nMax = nEnd - nStart + 1;
		}
		nMiddle++;
	}

	nSize = returnEnd - returnStart + 1;

	returnChar = (char *)malloc(sizeof(char)*(nSize + 1));

	strncpy(returnChar, &s[returnStart], nSize);
	returnChar[nSize] = '\0';

	return returnChar;
}