class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Init
        int dx[3] = {-1, 0, 1};
        int n = matrix.size();

        // Accumulate the minimum value of last row
        for (int i=1; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int temp = INT_MAX;
                for (int& x: dx) {
                    if (j+x < 0 || j+x >= n) {
                        continue;
                    }
                    temp = min(temp, matrix[i-1][j+x]);
                }
                matrix[i][j] += temp;
            }
        }

        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};

