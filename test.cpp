
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int lengthOfLongestSubstring(char * s);
char *inputString(FILE* fp, size_t size);


using namespace std;

int main(){
	char *s;

	printf("input:");

	s = inputString(stdin, 10);

	int nMax = lengthOfLongestSubstring(s);

	cout << nMax;

	system("pause");



}

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

int lengthOfLongestSubstring(char * s) {
	int nStart = 0, nEnd = 0, nMax = 0, nTemp = 0;

	int loc[128];
	memset(loc,-1,128*sizeof(int));

	for (nEnd = 0; nEnd< strlen(s); nEnd++) {
		nTemp = loc[s[nEnd]];
		loc[s[nEnd]] = nEnd;
		if (nTemp >= nStart) {
			nMax = MAX(nMax, nEnd - nStart);
			nStart = nTemp + 1;
		}
	}
	nMax = MAX(nMax, nEnd - nStart);

	return nMax;
}