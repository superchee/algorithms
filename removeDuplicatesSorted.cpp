#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 1) return numsSize;

    int returnSize = 1, Idx = 1;

    for (int i = 1; i < numsSize; i++){
        while(nums[i] == nums[i-1]){
            i++;
            if (i == numsSize){
                return returnSize;
            }
        }

        nums[Idx++] = nums[i];
        returnSize++;
    }
    return returnSize;

}

int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 1) return numsSize;

    int Idx = 0;

    for (int i = 1; i < numsSize; i++){
        if (nums[i] != nums[Idx]){
            nums[++Idx] = nums[i];            
        }
    }
    return Idx+1;

}