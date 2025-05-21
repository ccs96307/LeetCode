class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstZeroRow = -1;
        int firstZeroCol = -1;

        for (int i=0; i<matrix.size(); ++i) {
            bool canBreak = false;
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    firstZeroRow = i;
                    firstZeroCol = j;
                    canBreak = true;
                    break;
                }
            }

            if (canBreak) {
                break;
            }
        }

        if (firstZeroRow == -1 || firstZeroCol == -1) {
            return;
        }

        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[firstZeroRow][j] = 0;
                    matrix[i][firstZeroCol] = 0;
                }
            }
        }

        for (int i=0; i<matrix.size(); ++i) {
            if (i == firstZeroRow) {
                continue;
            }

            if (matrix[i][firstZeroCol] == 0) {
                for (int j=0; j<matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j=0; j<matrix[0].size(); ++j) {
            if (j == firstZeroCol) {
                continue;
            }

            if (matrix[firstZeroRow][j] == 0) {
                for (int i=0; i<matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i=0; i<matrix.size(); ++i) {
            matrix[i][firstZeroCol] = 0;
        }

        for (int j=0; j<matrix[0].size(); ++j) {
            matrix[firstZeroRow][j] = 0;
        }
    }
};

