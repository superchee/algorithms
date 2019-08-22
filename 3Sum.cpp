#include <cstring>
#include <stdlib.h>

int compare(const void * a, const void * b){
    return *(int*)a - *(int*)b;
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int nStart = 0, nEnd = 0, nSum = 0, nTarget = 0, nblock = 64;
    int** returnArray = NULL;
	*returnSize = 0;

                
    returnArray = (int**)malloc(sizeof(int*)*nblock);
    if (!returnArray) return NULL;
    


    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 2; i++){
        nStart = i+1;
        nEnd = numsSize-1;
        nTarget = -nums[i];
        if (nums[i] > 0) break;
        while (nStart < nEnd){
            nSum = nums[nStart] + nums[nEnd];
            if (nSum < nTarget){
                nStart++;
            }
            else if(nSum > nTarget){
                nEnd--;
            }
            else {
                returnArray[*returnSize] = (int*)malloc(sizeof(int)*3);
                if (!returnArray[*returnSize]) return NULL;
                returnArray[*returnSize][0] = nums[i];
                returnArray[*returnSize][1] = nums[nStart];
                returnArray[*returnSize][2] = nums[nEnd];

                while (nStart < nEnd && nums[nStart] == returnArray[*returnSize][1]){
                    nStart++;
                }
                while (nStart < nEnd && nums[nEnd] == returnArray[*returnSize][2]){
                    nEnd--;
                }
                (*returnSize)++;
                if((*returnSize) == nblock){
                    nblock *= 2;
                    returnArray = (int**)realloc(returnArray, sizeof(int*)*nblock);
                    }
            }
        }
        while (i<numsSize-2 && nums[i+1] == nums[i]){
            i++;
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    if (!(*returnColumnSizes)) return NULL;
    for (int j = 0; j<*returnSize; j++){
        (*returnColumnSizes)[j] = 3;
    }



    return returnArray;

}