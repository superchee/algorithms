#include <string.h>
#include <stdlib.h>
char * convert(char * s, int numRows){
    int nSize = 0, nIdx = 0, nNewIdx = 0;
    char *returnChar = NULL;
    nSize = strlen(s);
    returnChar = (char *)malloc(sizeof(char)*(nSize +1));
    
    if (nSize <= numRows){
        return s;
    }
    
    if (numRows == 1){
        return s;
    }


    for (int r = 0; r < numRows; r++){
        nIdx = r;
        if (r == 0){
            while(nIdx < nSize){
                returnChar[nNewIdx++] = s[nIdx];
                nIdx += 2*numRows - 2;
            }
        }
        else if(r == numRows - 1){
            while(nIdx < nSize){
                returnChar[nNewIdx++] = s[nIdx];
                nIdx += 2*numRows - 2;
            }
        }
        else{
            while(nIdx < nSize){
                returnChar[nNewIdx++] = s[nIdx];
                nIdx += 2*(numRows -r) -2;
                if (nIdx > nSize){
                    break;
                }
                returnChar[nNewIdx++] = s[nIdx];
                nIdx += 2*(r+1) -2;
            }
        }

    }
    returnChar[nSize] = '\0';
    return returnChar;

}