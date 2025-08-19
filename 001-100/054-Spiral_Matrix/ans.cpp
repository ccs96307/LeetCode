class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> results;

        while (top <= bottom && left <= right) {
            for (int c=left; c<=right; ++c) {
                results.emplace_back(matrix[top][c]);
            }
            ++top;

            for (int r=top; r<=bottom; ++r) {
                results.emplace_back(matrix[r][right]);
            }
            --right;

            if (top <= bottom) {
                for (int c=right; c>=left; --c) {
                    results.emplace_back(matrix[bottom][c]);
                }
                --bottom;
            }

            if (left <= right) {
                for (int r=bottom; r>=top; --r) {
                    results.emplace_back(matrix[r][left]);
                }
                ++left;
            }
        }

        return results;
    }
};

