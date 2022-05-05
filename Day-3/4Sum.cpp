/*
18. 4Sum
Medium

6139

697

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // vector<vector<int>> ans;
        // for(int i = 0; i < n-3; i++){
        //     for(int j = i + 1; j < n-2; j++){
        //         for(int k = j + 1; k < n-1; k++){
        //             for(int l = k+1; l < n; l++){
        //                 if(nums[i] + nums[j] + nums[k] + nums[l] == target){
        //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
        //                     ans.push_back(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return ans;
        
        // Approach- 2> Optimised Approach
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i + 1; j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                
                int tSum = target - (nums[i] + nums[j]);
                int l = j + 1, h = n-1;
                while(l < h){
                    if(nums[l] + nums[h] == tSum){
                        vector<int> temp{nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(temp);
                        while(l < h && nums[l] == nums[l+1]){
                            l++;
                        }
                        while(l < h && nums[h] == nums[h-1]){
                            h--;
                        }
                        l++;
                        h--;
                    }else if(nums[l] + nums[h] < tSum){
                        l++;
                    }else{
                        h--;
                    }
                }
            }
        }
        return ans;
    }
};
