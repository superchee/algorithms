#include <stdlib.h>
#include <string.h>

static const char* phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


void Combination(char* digits, int nStart, int nEnd, char* string, char** combinations, int* cIdx){
    if(nStart<=nEnd){
        const char* temp = phone[digits[nStart] - '0'];
        for (int i = 0; i < strlen(temp); i++){
            string[nStart] = temp[i];
            Combination(digits, nStart+1, nEnd, string, combinations, cIdx);
        }
    }
    else{
        string[nStart] = '\0';
        combinations[*cIdx] = (char*)malloc(sizeof(char)*(nEnd+2));
        strcpy(combinations[*cIdx], string);
        (*cIdx)++;
    }
    
}

char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    if (digits == NULL){
        return NULL;
    } 

    int nDLen = strlen(digits), pIdx = 0;

    if (nDLen == 0) return NULL;

    *returnSize = 1;

    for (int i = 0; i < nDLen; i++){
        pIdx = (int)digits[i] - '0';
        *returnSize *= strlen(phone[pIdx]);
    }

    char** combinations = (char**)malloc(sizeof(char*)*(*returnSize));
    char* string = (char*)malloc(sizeof(char)*(nDLen+1));
    int* cIdx = (int*)malloc(sizeof(int)*1);
    *cIdx = 0;

    Combination(digits, 0, nDLen-1 , string, combinations, cIdx);

    return combinations;
}