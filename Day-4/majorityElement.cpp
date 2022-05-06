/*
169. Majority Element
Easy

9531

335

Add to List

Share
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
Accepted
1,218,259
Submissions
1,9
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        
        for(int i = 0; i < n; i++){
            map[nums[i]]++;
        }
        int ans;
        for(auto x : map){
            if(x.second > n/2){
                ans = x.first;
                break;
            }
        }
        
        return ans;
    }
};
