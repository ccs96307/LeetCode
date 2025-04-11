class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Init
        int i = 0;
        int j = 0;
        
        // Finding i
        for (i=0; i<matrix.size(); ++i) {
            if (i+1 >= matrix.size() || (target >= matrix[i][0] && target < matrix[i+1][0])) break;
        }
        
        // Finding j
        for (j=0; j<matrix[0].size(); ++j) {
            if (matrix[i][j] == target) return true;
        }
        
        return false;
    }
};

