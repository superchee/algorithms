#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor){
    int res = 0, temp = 0, m = 0, ans = 0;
    if (divisor == INT_MIN) return dividend == INT_MIN? 1:0;

    if(dividend == INT_MIN){
        if(divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        dividend += abs(divisor);
        ans = 1;
    }

    int dvd = abs(dividend), dvs = abs(divisor); 
    int sign = dividend > 0 ^ divisor >0 ? -1:1;


    while (dvd >= dvs ){
        temp = dvs;
        m = 1;
        while ( dvd - temp >= temp ){
            temp<<=1;
            m<<=1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign*ans;
}
