class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // Init
        unordered_map<string, int> counter;

        // Count
        for (vector<string>& path: paths) {
            ++counter[path[0]];
            --counter[path[1]];
…    }
};

