class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows({1});

        for (int index=0; index<rowIndex; ++index) {
            rows.emplace_back(1);

            for (int i=rows.size()-2; i>0; --i) {
                rows[i] += rows[i-1];
            }
        }

        return rows;
    }
};

