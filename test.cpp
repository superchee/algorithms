
#include <iostream>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


char *inputString(FILE* fp, size_t size);


bool safeAdd(int a, int b);
int myAtoi(char * str);

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
    int nInput, nReturn;

	nReturn = myAtoi(s);


	cout << nReturn << endl;

	system("pause");



}


int myAtoi(char * str) {
    int nSum = 0, nTemp;
    int nSign = 1, nIdx = 0;

    if (str == NULL)
        return 0;

    while (str[nIdx] == ' ') nIdx++;
    if (str[nIdx] == '+'){
        nIdx++;
    }
    else if(str[nIdx] == '-'){
        nSign = -1;
        nIdx++;
    }
    while (str[nIdx] != '\0'){
        if (str[nIdx] < '0' || str[nIdx] > '9') break;
        nTemp = str[nIdx++] - '0';

        if (nSum > (INT_MAX - nTemp)/10) return nSign > 0? INT_MAX:INT_MIN;

        nSum = nSum*10 + nTemp;
    }
    
    return nSign * nSum;
}