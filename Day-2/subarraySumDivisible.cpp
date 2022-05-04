/*
974. Subarray Sums Divisible by K
Medium

2764

133

Add to List

Share
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Brute Force
    //     int count = 0, sum = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         sum = 0;
    //         for(int j = i; j < nums.size(); j++){
    //             sum += nums[j];
    //             if(sum % k == 0){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
        
       // Approach->2 : prefix sum
       
        int n = nums.size();
        if(n==0) return 0;
        
        int i = 0, count = 0;
        int curr_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;// this is done because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        
        while(i<n)
        {
            curr_sum+= nums[i++];
            int rem = curr_sum % k;
            if(rem<0) rem += k;
            
            if(mp.find(rem)!=mp.end())
                count+=mp[rem];
            
            mp[rem]++;
            
        }
        return count;
    }
};
