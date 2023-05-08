class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // Init
        int count = 0;
        int _size = mat.size() - 1;

        // Couting
        for (int i=0; i<=_size; ++i) {
            count += mat[i][i] + mat[_size-i][i];
        }

        // If mattrix size is odd number
        if (_size % 2 == 0) {
            count -= mat[_size/2][_size/2];
        }

        return count;
    }
};

