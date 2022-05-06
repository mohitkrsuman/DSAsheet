/*
79. Word Search
Medium

9157

348

Add to List

Share
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
*/class Solution {
private:
    bool dfs(vector<vector<char>> &board, int i, int j, int count, string word){
        if(count == word.size()){
            return true;
        }
        // Base Case if we apply dfs first row, col
        if(i == -1 || i == board.size() || j == -1 || j == board[0].size() || board[i][j] != word.at(count)){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool found = dfs(board, i+1, j, count+1, word) ||
                     dfs(board, i, j+1, count+1, word) ||
                     dfs(board, i-1, j, count+1, word) ||
                     dfs(board, i, j-1, count+1, word);
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word.at(0) && dfs(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
private:
    bool dfs(vector<vector<char>> &board, int i, int j, int count, string word){
        if(count == word.size()){
            return true;
        }
        // Base Case if we apply dfs first row, col
        if(i == -1 || i == board.size() || j == -1 || j == board[0].size() || board[i][j] != word.at(count)){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool found = dfs(board, i+1, j, count+1, word) ||
                     dfs(board, i, j+1, count+1, word) ||
                     dfs(board, i-1, j, count+1, word) ||
                     dfs(board, i, j-1, count+1, word);
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word.at(0) && dfs(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
