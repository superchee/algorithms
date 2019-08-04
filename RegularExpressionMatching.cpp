#include <stdio.h>
#include <string.h>
#include <stdlib.h>



bool isMatch(char * s, char * p) {
    int nS = strlen(s), nP = strlen(p);
    bool *bMatch, pre = false, temp = false;
    bMatch = (bool *)malloc(sizeof(bool)*(nP+1));
    memset(bMatch, false, sizeof(bool)*(nP+1));
    for (int i = 0; i <=nS; i++){
        pre = bMatch[0];
        bMatch[0] = !i;
        for (int j = 1; j <= nP; j++){
            temp = bMatch[j];
            if (j > 1 && p[j - 1] == '*'){
                bMatch[j] = bMatch[j-2] || (i && bMatch[j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            }
            else {
                bMatch[j] = i && pre && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
            pre = temp;
        }
    }

    return bMatch[nP];
}