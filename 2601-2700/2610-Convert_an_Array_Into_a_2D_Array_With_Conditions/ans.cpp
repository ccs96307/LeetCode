class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Init
        int _max = 0;
        unordered_map<int, int> num2times;

        // Count
        for (int& num: nums) {
            ++num2times[num];
            _max = max(_max, num2times[num]);
        }

        // Filling results
        vector<vector<int>> results(_max, vector<int>({}));
        for (auto& it: num2times) {
            for (int i=0; i<it.second; ++i) {
                results[i].emplace_back(it.first);
            }
        }

        return results;
    }
};

