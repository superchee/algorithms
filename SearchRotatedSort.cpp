#include <stdlib.h>


int binarySearchBack(int* nums, int nStart, int nEnd, int target){
    if (nStart > nEnd) return -1;
    int mid = nStart + ((nEnd - nStart)>>1);

    if (nums[mid] == target) return mid;

    if (nums[mid] < target){
        if (nums[mid] <= nums[nEnd] && nums[nEnd] < nums[nStart] && nums[nEnd] < target){
            return binarySearch(nums, nStart, mid - 1, target);                
        }
        else{
            return binarySearch(nums, mid + 1, nEnd, target);
        }
        
    }else{
        if (nums[mid] >= nums[nStart] && nums[nEnd] < nums[nStart] && nums[nStart] > target){
            return binarySearch(nums, mid + 1, nEnd, target);
        }
        else{
             return binarySearch(nums, nStart, mid - 1, target);           
        }

    }
    
}

int binarySearch(int* nums, int nStart, int nEnd, int target){
    if (nStart > nEnd) return -1;
    int mid = nStart + ((nEnd - nStart)>>1);

    if (nums[mid] == target) return mid;

    if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])){
        return binarySearch(nums, mid + 1, nEnd, target); 
    }else{
        return binarySearch(nums, nStart, mid - 1, target);           
    }
    
}

int search(int* nums, int numsSize, int target){
    if (!nums || numsSize == 0) return -1;

    return binarySearch(nums, 0, numsSize-1, target);
}

