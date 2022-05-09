/*14. Longest Common Prefix
Easy

7885

2983

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        // traversing all char of 1st string
        for(int i = 0; i < strs[0].size(); i++){
           char ch = strs[0][i];
            
            bool match = true;
            // for comparing character rest of the string
            for(int j = 1; j < n; j++){
                
                if(strs[j].size() < i || ch != strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }else{
                ans += ch;
            }
        }
        return ans;
    }
};
