/*
493. Reverse Pairs
Hard

2801

180

Add to List

Share
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/

class Solution {
private:
    void _merge(vector<int>& nums, int low, int mid, int high, int &reversePairCount) {
    int leftInd = low, rightInd = mid+1, r = rightInd, temp[high-low+1], tempInd = 0, counter = 0;
    // 4 6 8,  1 2 3
    while(leftInd<=mid) {
        while( r<=high && (nums[leftInd] > (long)2*nums[r]) ) counter++, r++;
        reversePairCount+= counter;
        while( rightInd<=high && nums[rightInd]<=nums[leftInd] ) {
            temp[tempInd++] = nums[rightInd++];
        }
        temp[tempInd++] = nums[leftInd++];
    }
    while(rightInd<=high) {
        temp[tempInd++] = nums[rightInd++];
    }
    for(int i=0; i<tempInd; i++) nums[low++] = temp[i];
}

void _mergeSort(vector<int>& nums, int low, int high, int &reversePairCount) {
    if(low < high) {
        int mid = low + (high-low)/2;
        _mergeSort(nums, low, mid, reversePairCount);
        _mergeSort(nums, mid+1, high, reversePairCount);
        _merge(nums, low, mid, high, reversePairCount);
    }
}
public:
    int reversePairs(vector<int>& nums) {
        int reverseCount = 0;
        int n = nums.size();
        if(n <= 1){
            return reverseCount;
        }
        _mergeSort(nums, 0, n-1, reverseCount);
        return reverseCount;
    }
};
