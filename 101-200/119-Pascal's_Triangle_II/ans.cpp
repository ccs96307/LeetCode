class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previousRows({1});
        vector<int> currentRows;

        for (int index=0; index<rowIndex; ++index) {
            for (int i=0; i<=previousRows.size(); ++i) {
                if (i > 0 && i < previousRows.size()) {
                    currentRows.emplace_back(previousRows[i-1]+previousRows[i]);
                }
                else {
                    currentRows.emplace_back(1);
                }
            }

            previousRows = currentRows;
            currentRows.clear();
        }

        return previousRows;
    }
};

