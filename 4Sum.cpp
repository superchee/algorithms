#include <stdlib.h>


void MergeSort(int* nums, int numsSize){

    int* temp = (int*)malloc(sizeof(int)*numsSize);

    for (int i=0; i<numsSize; i++){
        temp[i] = nums[i];
    }

    MergeSplitSort(nums, temp, 0, numsSize-1);

    free(temp);
}

void MergeSplitSort(int* nums, int* temp, int nStart, int nEnd){

    if (nStart >= nEnd)
        return;
    
    int nMid = nStart + ((nEnd-nStart)>>1);

    MergeSplitSort(nums, temp, nStart, nMid);
    MergeSplitSort(nums, temp, nMid + 1, nEnd);

    Merge(nums, temp, nStart, nMid, nEnd);
}

void Merge(int* nums, int* temp, int nStart, int nMid, int nEnd){
    int k = nStart, i = nStart, j = nMid+1;
    while(i<=nMid && j<=nEnd){
        if (nums[i] < nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }
    while (i<=nMid){
        temp[k++] = nums[i++];
    }

    for(int m = nStart; m <=nEnd; m++){
        nums[m] = temp[m];
    }
}


void QuickSort(int* nums, int nStart, int nEnd){
    if(nStart >= nEnd)
        return;
    
    int pivot = RandomizedPartition(nums, nStart, nEnd);

    QuickSort(nums, nStart, pivot-1);
    QuickSort(nums, pivot+1, nEnd);
}

int RandomizedPartition(int* nums, int nStart, int nEnd){

    int pRIdx = rand()%(nEnd-nStart+1) + nStart;

    swap(nums+pRIdx, nums+nEnd);

    return Partition(nums, nStart, nEnd);

}

int Partition(int* nums, int nStart, int nEnd){
    int pivot = nums[nEnd];

    int pIdx = nStart;

    for(int i = nStart; i < nEnd; i ++){
        if (nums[i] < pivot){
            swap(nums+i, nums+pIdx);
            pIdx++;
        }
    }
    swap(nums+nEnd, nums+pIdx);

    return pIdx;
}

void swap(int* x, int* y){
    int temp  = *x;
    *x = *y;
    *y = temp;
}


int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}


int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){

    int nblock = 64;

    int** returnArray = (int**)malloc(sizeof(int*)*nblock);
    *returnSize = 0;
    
    MergeSort(nums, numsSize);
    
    //qsort(nums, numsSize, sizeof(int), comp);
    
    int nLeft = 0, nRight = 0,  nSum = 0;

    for(int i = 0; i<numsSize-3; i++){
        if (nums[i]+ nums[numsSize-1] + nums[numsSize-2] + nums[numsSize-3] < target)
            continue;
        if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
            break;
        for(int j = i+1; j < numsSize - 2; j++){
            
            if (nums[i] + nums[j] + nums[numsSize-1] + nums[numsSize-2] < target)
                continue;
            
            if (nums[i] + nums[j] + nums[j+1] + nums[j+2] >target )
                break;
            
            nLeft = j+1;
            nRight = numsSize - 1;
            while(nLeft < nRight){
                nSum = nums[i] + nums[j] + nums[nLeft] + nums[nRight];
                if(nSum < target){
                    do{
                        nLeft++;
                    }while(nums[nLeft] == nums[nLeft-1] && nLeft < nRight);
                }
                else if(nSum > target){
                    do{
                        nRight--;
                    }while(nums[nRight] == nums[nRight+1] && nLeft < nRight);
                }
                else{
                    returnArray[*returnSize] = (int*)malloc(sizeof(int)*4);
                    returnArray[*returnSize][0] = nums[i];
                    returnArray[*returnSize][1] = nums[j];
                    returnArray[*returnSize][2] = nums[nLeft];
                    returnArray[*returnSize][3] = nums[nRight];

                    do{
                        nLeft++;
                    }while(nLeft < nRight && nums[nLeft] == nums[nLeft-1] );

                    do{
                        nRight--;
                    }while(nLeft < nRight && nums[nRight] == nums[nRight+1]);

                    (*returnSize)++;

                    if(*returnSize == nblock){
                        nblock *= 2;
                        returnArray = (int**)realloc(returnArray, sizeof(int*)*nblock);
                    }

                }
            }
            while(j < numsSize-2 && nums[j+1] == nums[j]){
                j++;
            }
        }
        while (i < numsSize-3 && nums[i+1] == nums[i]){
            i++;
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++){
        (*returnColumnSizes)[i] = 4;
    }

    return returnArray;

}