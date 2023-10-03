class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Init
        vector<int> kWeakest;
        vector<pair<int, int>> rows;

        // Compute
        for (int i=0; i<mat.size(); ++i) {
            int value = 0;
            for (int& val: mat[i]) {
                if (val == 0) {
                    continue;
                }

                ++value;
            }

            rows.emplace_back(pair<int, int>({value, i}));
        }

        // Sort
        sort(rows.begin(), rows.end());

        // Get k-weakest
        for (int i=0; i<k; ++i) {
            kWeakest.emplace_back(rows[i].second);
        }

        return kWeakest;
    }
};

