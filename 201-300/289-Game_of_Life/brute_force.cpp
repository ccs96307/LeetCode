class Solution {
public:
    int alive(vector<vector<int>>& board, int i, int j) {
        int live = 0;
        int dead = 0;
        
        for (int _i=i-1; _i<=i+1; ++_i) {
            for (int _j=j-1; _j<=j+1; ++_j) {
                if (_i < 0 || _j < 0 || _i >= board.size() || _j >= board[0].size()) {
                    continue;
                }
                
                if (_i == i && _j == j) continue;
                
                if (board[_i][_j]) ++live;
                else ++dead;
            
            }
        }
        
        if (board[i][j] == 1) {
            if (live < 2 || live >= 4) return 0;
            else return 1;
        } 
        else if (live == 3) return 1;
        
        return board[i][j];
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        // Init
        vector<int> changes;
        
        // Record
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                changes.push_back(alive(board, i, j));
            }
        }
        
        // Update
        int n = board[0].size();
        for (int i=0; i<changes.size(); ++i) {
            board[i/n][i%n] = changes[i];
        }
    }
};

