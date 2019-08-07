#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize) {
	char * cComPre = NULL;
	cComPre = (char *)malloc(sizeof(char) * 1);
	cComPre[0] = '\0';
	if (strsSize == 0) return cComPre;


	int nIdx = 0, i = 0;
	bool bSame = true;

	while (*(*strs + nIdx) != '\0') {
		bSame = true;
		for (i = 1; i < strsSize; i++) {
			if (*(*(strs + i) + nIdx) == *(*strs + nIdx)) {
				continue;
			}
			else {
				bSame = false;
				break;
			}
		}

		if (bSame) {
			nIdx++;
			continue;
		}
		else
		{
			break;
		}

	}

	cComPre = (char *)realloc(cComPre, sizeof(char)*(nIdx + 1));

	strncpy(cComPre, *strs, nIdx);
	cComPre[nIdx] = '\0';

	return cComPre;

}