
#include <iostream>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


char *inputString(FILE* fp, size_t size);


bool safeAdd(int a, int b);

bool isPalindrome(int x);

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

	nReturn = isPalindrome(atoi(s));


	cout << nReturn << endl;

	system("pause");



}


bool isPalindrome(int x){
    int nR = 0, nTemp=0;
    int Input = x;
    if (Input < 0) return false;

    while (Input != 0){
        nTemp = Input%10;
        if (nR > (INT_MAX - nTemp)/10) return false;
        nR = nR*10 + nTemp;
        Input = Input/10;
    }
    return nR == x;
}