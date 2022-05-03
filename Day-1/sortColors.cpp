/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

class Solution {
    
private:
    void merge(vector<int> &nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right - mid;
        int *leftArr = new int[n1];
        int *rightArr = new int[n2];
        for(int i = 0; i < n1; i++){
            leftArr[i] = nums[left + i];
        }
        for(int j = 0; j < n2; j++){
            rightArr[j] = nums[mid + 1+ j];
        }
        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2){
            if(leftArr[i] <= rightArr[j]){
                nums[k] = leftArr[i++]; 
            }else{
                nums[k] = rightArr[j++];
            }
            k++;
        }
        
        while(i < n1){
            nums[k++] = leftArr[i++];
        }
        while(j < n2){
            nums[k++] = rightArr[j++];
        }
    }
    void mergeSortHelper(vector<int> &nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = (start+end)/2;
        mergeSortHelper(nums, start, mid);
        mergeSortHelper(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        mergeSortHelper(nums, 0, size-1);
    }
};
