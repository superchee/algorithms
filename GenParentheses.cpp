#include <stdlib.h>
#include <string.h>


static int block = 64;


void GenValidParenthesis(int nLeft, int nRight, char* string, int Idx, char c, char*** returnArray, int* returnSize, int n){



    if(c == '('){
        nLeft++;
    }
    else{
        nRight++;
    }
    string[Idx++] = c;

    if (Idx == 2*n){
        string[Idx] = '\0';
        (*returnArray)[*returnSize] = (char*)malloc(sizeof(char)*(2*n+1));
        strcpy((*returnArray)[*returnSize], string);
        (*returnSize)++;
        if (block == *returnSize){
            block *= 2;
            (*returnArray) = (char**)realloc((*returnArray), sizeof(char*)*block);
        }
    }

    if (nLeft < n){
        GenValidParenthesis(nLeft,nRight,string,Idx,'(', returnArray, returnSize, n);
    }

    if (nRight < nLeft){
        GenValidParenthesis(nLeft,nRight,string,Idx,')', returnArray, returnSize, n);       
    }


    
}


char ** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;

    char** returnArray = (char**)malloc(sizeof(char*)*block);

    char* string = (char*)malloc(sizeof(char)*(2*n+1));

    GenValidParenthesis(0,0,string,0,'(', &returnArray, returnSize, n);

    return returnArray;
}