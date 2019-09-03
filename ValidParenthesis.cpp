
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int longestValidParentheses(char * s){
    if (!s || *s == '\0') return 0;
    int nMaxL = 0, nLen = strlen(s);
    int* lookup = (int*)malloc(sizeof(int)*nLen);
    memset(lookup, 0, sizeof(int)*nLen);

    for(int i = 1; i < nLen; i++){
        if (s[i] == ')'){
            if (s[i-1]=='('){
                lookup[i] = (i>2?lookup[i-2]:0)+2;
            }else if (i - lookup[i - 1] > 0 && s[i - lookup[i - 1] - 1] == '(') {
                    lookup[i] = lookup[i - 1] + ((i - lookup[i - 1]) >= 2 ? lookup[i - lookup[i - 1] - 2] : 0) + 2;
            }
            nMaxL = MAX(nMaxL, lookup[i]);
        }
    }
    return nMaxL;
}