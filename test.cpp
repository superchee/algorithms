
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


char *inputString(FILE* fp, size_t size);
char * convert(char * s, int numRows);



using namespace std;
char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = (char *)realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = (char *)realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return (char *)realloc(str, sizeof(char)*len);
}

int main(){
	char *s;

	printf("input:");

	s = inputString(stdin, 10);

	char *reChar;
	reChar = convert(s, 4);

	cout << reChar << endl;

	system("pause");



}


char * convert(char * s, int numRows){
    int nSize = 0, nIdx = 0, nNewIdx = 0;
    char *returnChar = NULL;
    nSize = strlen(s);
    returnChar = (char *)malloc(sizeof(char)*(nSize +1));

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