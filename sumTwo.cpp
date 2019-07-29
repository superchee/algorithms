

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++){
        for (int j = 0; j < numsSize; j++){
            if (nums[j]==target - nums[i]){
                int* returnNums = (int*)malloc(sizeof(int)*2);
                returnNums[0]=i;
                returnNums[1]=j;
                *returnSize = 2;
                return returnNums;
            }
        }
    }
    return NULL;

}

