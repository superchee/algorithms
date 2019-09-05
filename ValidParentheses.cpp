#include <stdlib.h>
#include <string.h>

bool isValid(char * s){
    
    int nLen = strlen(s);
    if (nLen%2) return false;
    if (nLen == 0) return true;

    
    int nIdx = -1;
    int nSize = nLen>>1;
    char* stack = (char*)malloc(sizeof(char)*nSize);

    nSize--;

    
    for (int i = 0; i < nLen; i++){
        if (s[i] == ')'){
            if (nIdx >= 0 && stack[nIdx] == '('){
                nIdx--;
            }else{
                return false;
            }
        }else if (s[i] == ']'){
            if (nIdx >= 0 && stack[nIdx] == '['){
                nIdx--;
            }else{
                return false;
            }
        }else if (s[i] == '}'){
            if (nIdx >= 0 && stack[nIdx] == '{'){
                nIdx--;
            }else{
                return false;
            }
        }else{
            if (nIdx == nSize) return false;
            stack[++nIdx] = s[i];
        }
    }    
    
    return nIdx == -1;
}

bool isValidSecond(char * s){
    
    int nLen = strlen(s);
    if (nLen%2) return false;
    if (nLen == 0) return true;

    
    int nIdx = -1;
    int nSize = nLen>>1;
    char* stack = (char*)malloc(sizeof(char)*nSize);

    nSize--;
    
    for (int i = 0; i < nLen; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            if (nIdx >= nSize) return false;
            stack[++nIdx] = s[i];
        }
        else{
            if (nIdx >= 0 && s[i] == ')' && stack[nIdx] == '('){
                nIdx--;
            }else if (nIdx >=0 && s[i] == '}' && stack[nIdx] == '{'){
                nIdx--;
            }else if (nIdx >= 0 && s[i] == ']' && stack[nIdx] == '['){
                nIdx--;
            }else{
                return false;
            }
        }
    }
    return nIdx == -1;
}