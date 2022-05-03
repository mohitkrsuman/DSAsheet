/*
283. Move Zeroes
Easy

9020

242

Add to List

Share
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero = 0;
        int zero_cnt = 0;
        
        for(auto v : nums){
            if(v > 0){
                non_zero++;
            }else if(v == 0){
                zero_cnt++;
            }
        }
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[k++] = nums[i];
            }
        }
        for(int i = 0; i < zero_cnt; i++){
            nums[k++] = 0;
        }
    }
};
