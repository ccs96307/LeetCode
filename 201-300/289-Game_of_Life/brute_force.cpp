class Solution {
public:
    int countLiveAround(int i, int j, int m, int n, vector<vector<int>>& board) {
        static vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        int live = 0;
        for (auto [dy, dx]: dirs) {
            int x = j + dx;
            int y = i + dy;
            
            if (x >= 0 && x < n && y >= 0 && y < m && board[y][x] == 1) {
                ++live;
            }
        }

        return live;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> newBoard = board;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = countLiveAround(i, j, m, n, board);

                if (live < 2 || live > 3) {
                    newBoard[i][j] = 0;
                }
                else if (live == 3 && board[i][j] == 0) {
                    newBoard[i][j] = 1;
                }
                else {
                    newBoard[i][j] = board[i][j];
                }
            }
        }

        board = newBoard;
    }
};

