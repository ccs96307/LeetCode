class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // Init
        int m = mat.size();
        int n = mat[0].size();
        
        // Prevatation
        if (m*n != r*c) return mat;
        
        // Reshape to 1-D Matrix
        vector<int> oneDMat;
        vector<int> tempMat;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                oneDMat.push_back(mat[i][j]);
            }
        }
        
        // Reshape to r * c matrix
        mat.clear();
        for (int i=0; i<r*c; ++i) {
            tempMat.push_back(oneDMat[i]);
            
            if (tempMat.size() == c) {
                mat.push_back(tempMat);
                tempMat.clear();
            }
        }
        
        return mat;
    }
};

