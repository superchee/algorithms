#include <string.h>

int romanToInt(char * s){
    int nSize = strlen(s), sum = 0;
    
    for (int i = nSize - 1; i >= 0; i--){
        switch(s[i]){
            case 'I':
                sum += sum >= 5? -1:1;
                break;
            case 'V':
                sum += 5;
                break;
            case 'X':
                sum += sum >= 50 ? -10:10;
                break;
            case 'L':
                sum += 50;
                break;
            case 'C':
                sum += sum >= 500 ? -100: 100;
                break;
            case 'D':
                sum += 500;
                break;
            case 'M':
                sum += 1000;
                break;
            default:
                break;
        }
    }
    return sum;

}
