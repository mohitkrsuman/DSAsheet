/*
560. Subarray Sum Equals K
Medium

13004

422

Add to List

Share
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
Accepted
770,745
Submissions
1,742,115
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    // Approach -> prefix Sum
       unordered_map<int, int> map;
        int n = nums.size();
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            if(sum == k){
                count++;
            }
            if(map.find(sum-k)!=map.end()){
                count = map[sum-k]+count;
            }
            
            if(map.find(sum) != map.end()){
                map[sum]++;
            }else{
                map[sum]=1;
            }
        }
        return count;
    }
};
