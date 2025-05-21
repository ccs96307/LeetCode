class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Init
        std::set<int> rows;
        std::set<int> cols;

        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        std::set<int>::iterator itr;
        std::set<int>::iterator itc;

        for (itr=rows.begin(); itr!=rows.end(); ++itr) {
            for (int j=0; j<matrix[0].size(); ++j) {
                matrix[*itr][j] = 0;
            }
        }

        for (itc=cols.begin(); itc!=cols.end(); ++itc) {
            for (int i=0; i<matrix.size(); ++i) {
                matrix[i][*itc] = 0;
            }
        }
    }
};
