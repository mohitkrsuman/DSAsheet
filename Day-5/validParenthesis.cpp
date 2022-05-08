/*
20. Valid Parentheses
Easy

12873

576

Add to List

Share
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 
*/

class Solution {
public:
    bool isValid(string s) {
//         stack<char> st;
//         char x;
        
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
//                 st.push(s[i]);
//             }
//             if(st.empty()){
//                 return false;
//             }
            
//             switch (s[i]){
//                 case ')' :
//                     x = st.top();
//                     st.pop();
//                     if(x == '{' || x == '['){
//                         return false;
//                     }
//                     break;
//                 case ']' :
//                     x = st.top();
//                     st.pop();
//                     if(x == '(' || x == '{'){
//                         return false;
//                     }
//                     break;
//                 case '}' :
//                     x = st.top();
//                     st.pop();
//                     if(x == '(' || x == '['){
//                         return false;
//                     }
//                     break;
//             }
//         }
//         return st.empty();
        
        stack<char> st;
        char x;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            
            if(st.empty()){
                return false;
            }
            
            if(s[i] == ')'){
                x = st.top();
                st.pop();
                if(x == '{' || x == '['){
                    return false;
                }
            }else if(s[i] == '}'){
                x = st.top();
                st.pop();
                if(x == '(' || x == '['){
                    return false;
                }
            }else if(s[i] == ']'){
                x = st.top();
                st.pop();
                if(x == '{' || x == '('){
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};
