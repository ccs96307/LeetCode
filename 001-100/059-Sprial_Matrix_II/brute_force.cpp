class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Init
        vector<vector<int>> results(n, vector<int>(n, 0));
        int h = n;
        int w = n;
        int i = 0;
        int j = 0;
        int value = 1;
        int status = 1;
        
        while (value < n*n+1) {
            if (status == 1) {
                if (j < n && results[i][j] == 0) {
                    results[i][j] = value;
                    ++value;
                    ++j;
                }
                else {
                    --j;
                    ++i;
                    status = 2;
                }
            }
            else if (status == 2) {
                if (i < n && results[i][j] == 0) {
                    results[i][j] = value;
                    ++value;
                    ++i;
                }
                else {
                    --i;
                    --j;
                    status = 3;
                }
            }
            else if (status == 3) {
                if (j >= 0 && results[i][j] == 0) {
                    results[i][j] = value;
                    ++value;
                    --j;
                }
                else {
                    ++j;
                    --i;
                    status = 4;
                }
            }
            else if (status == 4) {
                if (i >= 0 && results[i][j] == 0) {
                    results[i][j] = value;
                    ++value;
                    --i;
                }
                else {
                    ++i;
                    ++j;
                    status = 1;
                }
            }
        }
        
        return results;
    }
};

