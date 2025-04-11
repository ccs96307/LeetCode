class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Init
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> newImg(m, vector<int>(n, 0));

        // Smoothing
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int _count = 0;
                int _sum = 0;
                for (int _dx=-1; _dx<=1; ++_dx) {
                    for (int _dy=-1; _dy<=1; ++_dy) {
                        int x = i + _dx;
                        int y = j + _dy;

                        if (x < 0 || y < 0 || x >= m || y >= n) {
                            continue;
                        }

                        ++_count;
                        _sum += img[x][y];
                    }
                }

                newImg[i][j] = _sum / _count;
            }
        }

        return newImg;
    }
};

