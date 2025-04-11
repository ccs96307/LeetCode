class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // Init
        vector<string> results;
        int ti = 0;

        for (int i=1; i<=n; ++i) {
            if (ti == target.size()) {
                break;
            }

            results.emplace_back("Push");

            if (i != target[ti]) {
                results.emplace_back("Pop");
            }
            else {
                ++ti;
            }
        }

        return results;
    }
};

