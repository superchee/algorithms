#include <stdlib.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    if (!*needle) return 0;

    int lenH = strlen(haystack), lenN = strlen(needle);
    
    for (int i = 0; i <= lenH-lenN; i++){
        if (haystack[i] == needle[0]){
            if(strncmp(haystack+i, needle, lenN) == 0){
                return i;
            }
        }
    }

    return -1;
}


bool strSame(char* s1, char* s2, int nSize){
    for(int i = 0; i<nSize; i++){
        if (s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

int strStr(char * haystack, char * needle){
    if (!*needle) return 0;

    int lenH = strlen(haystack), lenN = strlen(needle);

    for(int i = 0; i <= lenH-lenN; i++){
        if (haystack[i] == needle[0]){
            if(strSame(haystack+i, needle, lenN)){
                return i;
            }
        }
    }


    return -1;
}


int strStr(char * haystack, char * needle){
    if (!*needle) return 0;

    int nIdx = -1, n1 = 0, n2 = 0;

    while (haystack[n1]){
        if(haystack[n1] == needle[n2]){
            nIdx = n1;
            n1++;
            n2++;
            while(needle[n2]){
                if(haystack[n1++] != needle[n2++]){
                    n1 = nIdx;
                    n2 = 0;
                    nIdx = -1;
                    break;
                }
            }
            if (nIdx != -1){
                return nIdx;
            }
        }
        n1++;
    }
    return nIdx;
}

