/*
680. Valid Palindrome II
Easy

5587

301

Add to List

Share
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
*/

class Solution {
private:
    bool validPalindromeHelp(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        
        while(left < right){
            if(s[left] != s[right]){
                return validPalindromeHelp(s, left+1, right) || validPalindromeHelp(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};
