class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        // If matching is finished
        if (k >= word.size()) {
            return true;
        }
        
        // If current position (i, j) is out of boundary
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        
        // If the current character is mismatch the word
        if (board[i][j] != word[k]) {
            return false;
        }
        
        // Change the current board to prevent the DFS check the same character again 
        char temp = board[i][j];
        board[i][j] = 0;
        
        // DFS
        bool isExisted = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1);
        
        // Recovery
        board[i][j] = temp;
        
        return isExisted;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // Iter
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {                
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

