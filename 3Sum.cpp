#include <cstring>
#include <stdlib.h>

int compare(const void * a, const void * b){
    return *(int*)a - *(int*)b;
}

void swap(int* x, int* y){
    //*x = ((*y) * (*x))/(*y = *x);
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int* nums, int nStart, int nEnd){
    int pivot = nums[nEnd];

    int pIdx = nStart;

    for (int i = nStart; i < nEnd; i++){
        if (nums[i] < pivot){
            swap(nums+i, nums+pIdx);
            pIdx++;
        }
    }
    swap(nums+pIdx, nums+nEnd);
    return pIdx;
}




void quicksort(int * nums, int nStart, int nEnd){
    if (nStart >= nEnd)
        return;
    
    int pivot = partition(nums, nStart, nEnd);

    quicksort(nums, nStart, pivot-1);
    quicksort(nums, pivot+1, nEnd);

}

void merge(int* nums, int*temp, int nStart, int mid, int nEnd){
    int k=nStart, i=nStart, j=mid+1;
    while (i<=mid && j<=nEnd)
    {
        if(nums[i]<nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }
    while(i<=mid){
        temp[k++] = nums[i++];
    }
    for(int m = nStart; m<= nEnd; m++){
        nums[m] = temp[m];
    }
}

void mergesplitsort(int* nums, int* temp, int nStart, int nEnd){
    if (nStart >= nEnd)
        return;
    
    int mid = nStart + ((nEnd-nStart)>>1);

    mergesplitsort(nums, temp, nStart, mid);
    mergesplitsort(nums, temp, mid+1, nEnd);

    merge(nums, temp, nStart, mid, nEnd);
}

void mergesort(int* nums, int numsSize){
    int* temp = (int*)malloc(sizeof(int)*numsSize);

    for (int i = 0; i < numsSize; i++){
        temp[i] = nums[i];
    }
    mergesplitsort(nums, temp, 0, numsSize-1);
    free(temp);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int nStart = 0, nEnd = 0, nSum = 0, nTarget = 0, nblock = 64;
    int** returnArray = NULL;
	*returnSize = 0;

                
    returnArray = (int**)malloc(sizeof(int*)*nblock);
    if (!returnArray) return NULL;
    


    //qsort(nums, numsSize, sizeof(int), compare);

    //quicksort(nums, 0, numsSize-1);
    mergesort(nums, numsSize);

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