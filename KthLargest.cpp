
#include <stdlib.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int RandomPartition(int* nums, int nStart, int nEnd){
    int pivot = rand()%(nEnd-nStart+1) + nStart;
    swap(nums+pivot, nums+nEnd);
    
    return partition(nums, nStart, nEnd);
}

int partition(int* nums, int nStart, int nEnd){
    int pivot = nums[nEnd], nIdx = nStart;
    for(int i = nStart; i < nEnd; i++){
        if (nums[i] < pivot){
            swap(nums+i, nums+nIdx);
            nIdx++;
        }
    }
    swap(nums+nEnd, nums+nIdx);
    return nIdx;
}




int findKthLargest(int* nums, int numsSize, int k){
    if (!nums || numsSize == 0) return 0;

    k = numsSize - k;

    int nStart = 0, nEnd = numsSize-1, pivot = 0;
    while (nStart < nEnd){
        pivot = RandomPartition(nums, nStart, nEnd);
        if (pivot < k){
            nStart = pivot + 1;
        }else if (pivot > k){
            nEnd = pivot - 1;
        }else{
            break;
        }
    }
    return nums[k];
}

