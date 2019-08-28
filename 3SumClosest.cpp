#include <stdlib.h>


void Merge(int* nums, int*temp, int nStart, int nMid, int nEnd){
    int i = nStart, k = nStart, j = nMid+1;

    while (i <= nMid && j<= nEnd){
        if (nums[i]<nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }
    while (i <= nMid){
        temp[k++] = nums[i++];
    }

    for (int m = nStart; m<=nEnd; m++){
        nums[m] = temp[m];
    }
}


void MergeSplitSort(int* nums, int* temp, int nStart, int nEnd){

    if (nStart >= nEnd)
        return;
    
    int nMid = nStart + ((nEnd - nStart)>>1);

    MergeSplitSort(nums, temp, nStart, nMid);
    MergeSplitSort(nums, temp, nMid+1, nEnd);

    Merge(nums, temp, nStart, nMid, nEnd);

}




void MergeSort(int* nums, int numsSize){
    if (numsSize == 0)
        return;
    
    int* temp = (int*)malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++){
        temp[i] = nums[i];
    }

    MergeSplitSort(nums, temp, 0, numsSize-1);

    free(temp);

}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int* nums, int nStart, int nEnd){
    int pivot = nums[nEnd];
    int pIdx = nStart;

    for(int i = nStart; i < nEnd; i++){
        if(nums[i] < pivot){
            swap(nums+i, nums+pIdx);
            pIdx++;
        }
    }
    swap(nums+pIdx, nums+nEnd);
    return pIdx;
}

void quicksort(int* nums, int nStart, int nEnd){
    if (nStart >= nEnd)
        return;

    int pivot = partition(nums, nStart, nEnd);

    quicksort(nums, nStart, pivot-1);
    quicksort(nums, pivot+1, nEnd);
}




int threeSumClosest(int* nums, int numsSize, int target){
    if (numsSize==0 || nums == NULL)
        return 0;
    int nStart = 0, nEnd = 0, nMSum = INT_MAX, nSum = 0, nDiff = 0, nMDiff = INT_MAX;
    //MergeSort(nums, numsSize);
    quicksort(nums, 0, numsSize-1);

    for(int i = 0; i < numsSize-2; i++){
        nStart = i+1;
        nEnd = numsSize-1;
        while (nStart < nEnd){
            nSum = nums[i] + nums[nStart] + nums[nEnd];

            if (nSum < target){
                nStart++;
            }
            else if (nSum > target){
                nEnd--;
            }
            else{
                return nSum;
            }
            nDiff = nSum - target;

            if (abs(nDiff) < abs(nMDiff)){
                nMSum = nSum;
                nMDiff = nDiff;
            }
        }
    }

    return nMSum;
}