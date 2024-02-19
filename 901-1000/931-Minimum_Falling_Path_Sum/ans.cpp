class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Init
        int _min = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();

        // Accumulation
        for (int i=1; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int left = j-1 >= 0 ? matrix[i-1][j-1] : INT_MAX;
                int middle = matrix[i-1][j];
                int right = j+1 < n ? matrix[i-1][j+1] : INT_MAX;

                int temp = min(left, middle);
                matrix[i][j] += min(temp, right);
            }
        }

        // Find the minimal
        for (int j=0; j<n; ++j) {
            _min = min(_min, matrix[m-1][j]);
        }

        return _min;
    }
};
