class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // Init
        int n = 0;

        // Check
        for (int j=0; j<strs[0].size(); ++j) {
            for (int i=0; i<strs.size()-1; ++i) {
                if (strs[i][j] > strs[i+1][j]) {
                    ++n;
                    break;
                }
            }
        }

        return n;
    }
};

