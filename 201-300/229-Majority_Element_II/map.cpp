class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Init
        int n3 = nums.size() / 3;
        vector<int> results;
        unordered_map<int, int> counter;

        // Count
        for (int& num: nums) {
            ++counter[num];
        }

        // Results
        for (auto& it: counter) {
            if (it.second > n3) {
                results.emplace_back(it.first);
            }
        }

        return results;
    }
};

