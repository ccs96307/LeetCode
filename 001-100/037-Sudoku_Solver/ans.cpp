class Solution {
public:
    bool collision(vector<vector<char>>& board, int i, int j) {
        // Row
        for (int k=0; k<board.size(); ++k) {
            if (k == j) continue;
            if (board[i][k] == board[i][j]) return true;
        }
        
        // Column
        for (int k=0; k<board.size(); ++k) {
            if (k == i) continue;
            if (board[k][j] == board[i][j]) return true;
        }
        
        // Grid
        for (int si=i/3*3; si<i/3*3+3; ++si) {
            for (int sj=j/3*3; sj<j/3*3+3; ++sj) {
                if (si == i && sj == j) continue;
                if (board[si][sj] == board[i][j]) return true;
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // Init
        unordered_map<int, unordered_map<int, bool>> fixed_pos;
        int i = 0;
        int j = 0;
        
        // Record the fixed position
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board.size(); ++j) {
                if (board[i][j] == '.') fixed_pos[i][j] = false;
                else fixed_pos[i][j] = true;
            }
        }
        
        // Find the answer
        while (i < board.size()) {            
            // Carry
            if (j == board.size()) {
                ++i;
                j = 0;
                continue;
            }
            
            // The current position is fixed
            if (fixed_pos[i][j] == true) {
                ++j;
            }
            
            // The current position is NULL
            else {
                if (board[i][j] == '.') {
                    board[i][j] = '1';
                }
                else if (int(board[i][j])-48 <= 8) {
                    board[i][j] = (char)(int(board[i][j])+1);
                }
                else if (board[i][j] == '9') {
                    board[i][j] = '.';
                    --j;
                    if (j < 0) {
                        --i;
                        j = board.size()-1;
                    }
                    
                    while (fixed_pos[i][j] == true) {
                        --j;
                        if (j < 0) {
                            --i;
                            j = board.size()-1;
                        }
                    }
                    
                    continue;
                }
                
                // Check not collision
                if (collision(board, i, j)) {
                    continue;
                }
                else {
                    ++j;       
                }
            }
        }
    }
};

