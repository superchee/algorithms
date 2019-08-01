#include <limits.h>

bool isPalindrome(int x){
    int nR = 0, nTemp=0;
    int nO = x;
    if (nO < 0) return false;
    if (nO == 0) return true;
    
    while (nO != 0){
        nTemp = nO%10;
        if (nR > (INT_MAX - nTemp)/10) return false;
        nR = nR*10 + nTemp;
        nO = nO/10;
    }
    if (nR == x) return true;
    
    return false;

}