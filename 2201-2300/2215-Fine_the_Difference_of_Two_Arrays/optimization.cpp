class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Init
        unordered_set<int> count1(nums1.begin(), nums1.end());
        unordered_set<int> count2(nums2.begin(), nums2.end());
        vector<vector<int>> results(2, vector<int>());

        // Fill in `results`
        for (auto& num: count1) {
            if (!count2.count(num)) {
                results[0].emplace_back(num);
            }
        }
        for (auto& num: count2) {
            if (!count1.count(num)) {
                results[1].emplace_back(num);
            }
        }

        return results;
    }
};

