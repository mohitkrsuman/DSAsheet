/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 
*/

#include <bits/stdc++.h>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      // Approach -> 1 (using sorting)
       int n = nums.size();
       sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1; 
        
      // Approach -> 2 (using Hashmap)
       unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
          map[nums[i]]++;
        }
        int ans;
        for(auto v : map){
          if(v.second > 1){
            return v.first;
          }
        }
         return -1; 
        
        // Approach (using Binary Search)
         int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
    
    // Approach -> 4(tortoise and hare approach)
    int slow = nums[0];
    int fast = nums[0];
    
    do{
        slow = nums[slow ];
        fast = nums[nums[fast]];
    }while(slow != fast);
    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
    }
};
