class Solution {
public:
    bool rowCollision(vector<vector<char>>& board, int i, int j) {
        for (int k=0; k<board.size(); ++k) { 
            if (k == j) continue;            
            if (board[i][k] == board[i][j]) return true;
        }
        return false;
    }
    
    bool colCollision(vector<vector<char>>& board, int i, int j) {
        for (int k=0; k<board.size(); ++k) {
            if (k == i) continue;
            if (board[k][j] == board[i][j]) return true;
        }
        return false;
    }
    
    bool gridCollision(vector<vector<char>>& board, int i, int j) {
        int si = i / 3 * 3;
        int ei = i / 3 * 3 + 3;
        int sj = j / 3 * 3;
        int ej = j / 3 *3 + 3;
        
        for (int temp_i=si; temp_i<ei; ++temp_i) {
            for (int temp_j=sj; temp_j<ej; ++temp_j) {
                if (temp_i == i && temp_j == j) continue;
                if (board[temp_i][temp_j] == board[i][j]) return true;
            }
        }
        
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board.size(); ++j) {
                if (board[i][j] == '.') continue;
                if (rowCollision(board, i, j) ||
                    colCollision(board, i, j) ||
                    gridCollision(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};
