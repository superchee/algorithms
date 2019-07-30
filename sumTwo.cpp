

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSumBruteForce(int* nums, int numsSize, int target, int* returnSize){
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

#define RETURN_SIZE 2

int compare(const void* a, const void* b){
    return (*(*(int**)a)-*(*(int**)b));
}

int* twoSumSort(int* nums, int numsSize, int target, int* returnSize){
    int** numIdx = NULL;
    int* returnIdx = NULL;
    int nStart=0, nEnd=0, nSum=0;

    numIdx = (int**)malloc(sizeof(int*)*numsSize);
    for (int i=0; i<numsSize; i++){
        numIdx[i] = &nums[i];
    }

    qsort(numIdx, numsSize, sizeof(int*), compare);

    nStart = 0;
    nEnd = numsSize -1;
    while (nStart!=nEnd){
        nSum = *numIdx[nStart] + *numIdx[nEnd] ;
        if (nSum < target){
            ++nStart;
            continue;
        }
        else if(nSum == target){
            *returnSize = 2;
            returnIdx = (int*) malloc(sizeof(int)*RETURN_SIZE);
            returnIdx[0] = numIdx[nStart] - nums;
            returnIdx[1] = numIdx[nEnd] - nums;
            return returnIdx;

        }
        else{
            --nEnd;
            continue;
        }
    }
    *returnSize = 0;

    return NULL;
}

