/*
442. Find All Duplicates in an Array
Medium

6082

248

Add to List

Share
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans; 
        int n = nums.size();
        if(nums.empty()){
            return {};
        }
        
        for(int i = 0; i < n; i++){
            if(nums[abs(nums[i])-1] < 0){
                ans.push_back(abs(nums[i]));
            }
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        return ans;
       
    }
};
