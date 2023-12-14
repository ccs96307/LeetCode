class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // Init
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<int> onesRow(rowSize, 0);
        vector<int> onesCol(colSize, 0);
        vector<int> zerosRow(rowSize, 0);
        vector<int> zerosCol(colSize, 0);

        // Count the accumulates of columns and rows
        for (int i=0; i<rowSize; ++i) {
            for (int j=0; j<colSize; ++j) {
                if (grid[i][j] == 1) {
                    ++onesRow[i];
                    ++onesCol[j];
                }
                else {
                    ++zerosRow[i];
                    ++zerosCol[j];
                }
            }
        }

        // Fill the results
        for (int i=0; i<rowSize; ++i) {
            for (int j=0; j<colSize; ++j) {
                int element = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
                grid[i][j] = element;
            }
        }

        return grid;
    }
};

