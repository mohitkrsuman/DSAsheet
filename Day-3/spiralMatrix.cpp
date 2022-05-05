/*
Medium

7075

828

Add to List

Share
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        int total = row*col, count = 0;
        while(count < total){
           // to print starting row
           for(int i = startingCol; count < total && i <= endingCol; i++){
               result.push_back(matrix[startingRow][i]);
               count++;
           }
           startingRow++;
            
          // to print ending col
            for(int i = startingRow; count < total && i <= endingRow; i++){
                result.push_back(matrix[i][endingCol]);
                count++;

            }
            endingCol--;
            
            // to print ending row (right->left)
            for(int i = endingCol; count < total && i >= startingCol; i--){
                result.push_back(matrix[endingRow][i]);
                count++;

            }
            endingRow--;
            
            // to print starting col(bottom->top)
            for(int i = endingRow; count < total && i >= startingRow; i--){
                result.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
            
        }
        return result;
    }
};
