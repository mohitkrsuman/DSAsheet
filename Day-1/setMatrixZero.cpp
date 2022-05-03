/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Approach-1> Brute force
        // Approach-2> using two temorary arrays
        // Time Complexity = O(m*n), Auxilliary Space = O(m+n)
        int r = matrix.size();
        int c = matrix[0].size();
        bool row[r];
        bool col[c];
        
        int i, j;
        
        for(i = 0; i < r; i++){
            row[i] = 1;
        }
        for(i = 0; i < c; i++){
            col[i] = 1;
        }
        
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                if(row[i] == 0 || col[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Approach-3> using givem matrix 1st array and col in place of auxilliary arrays;
        // Time Complexity : O(m*n)
        // Auxilliary space : O(1)
        
        bool row_flag = true;
        bool col_flag = true;
        
        int r = matrix.size();
        int c = matrix[0].size();
        // Updating the first row and col if 0 is encountered
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0 && matrix[i][j] == 0){
                    row_flag = false;
                }
                
                if(j == 0 && matrix[i][j] == 0){
                    col_flag = false;
                }
                
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        // Modify the input matrix using first row and col
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Modify first row if there was any 0
        if(row_flag == false){
            for(int i = 0; i < c; i++){
                matrix[0][i] = 0;
            }
        }
        
        // Modify first col if there was any 0
        if(col_flag == false){
            for(int i = 0; i < r; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
