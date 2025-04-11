class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Init
        int i = 0;
        int idx = 0;
        unordered_map<string, int> counter;
        unordered_map<string, bool> isUsed;

        for (auto& c: arr) {
            ++counter[c];
        }

        for (i=0; i<arr.size(); ++i) {
            if (isUsed[arr[i]]) {
                continue;
            }

            if (counter[arr[i]] == 1) {
                ++idx;

                if (idx == k) {
                    return arr[i];
                }
            }
        }

        return "";
    }
};
