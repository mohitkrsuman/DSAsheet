/*
22. Generate Parentheses
Medium

12731

491

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
*/

class Solution {
private:
    void addingPar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0){
            v.push_back(str);
            return;
        }
        if(m > 0){
            addingPar(v, str+")", n, m-1);
        }
        if(n > 0){
            addingPar(v, str+"(", n-1, m+1);
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingPar(res, "", n, 0);
        return res;
    }
};
