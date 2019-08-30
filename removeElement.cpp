#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int nStart = 0, nEnd = numsSize - 1;

    while (nStart <= nEnd){
        if(nums[nStart] == val){
            while(nums[nEnd] == val && nStart < nEnd){
                nEnd--;
            }
            nums[nStart] = nums[nEnd];
            nEnd--;
        }
        nStart++;
    }

    return nEnd+1;
    
}

int removeElement(int* nums, int numsSize, int val){
    int k = 0;
    for (int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[k++] = nums[i];
        }
    }

    return k;
}