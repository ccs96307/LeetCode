class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Init
        int i = 0;
        int j = matrix[0].size() - 1;
        
        // Finding
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) ++i;
            else --j;
        }
        
        return false;
    }
};

