class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Init
        vector<int> duplicated;
        vector<vector<int>> results(2, vector<int>{});

        // Sort
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Drop duplicated
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

        // Find difference
        for (int i=0; i<nums1.size(); ++i) {
            for (int j=0; j<nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    duplicated.emplace_back(nums1[i]);
                    break;
                }
            }
        }

        for (int i=0; i<nums1.size(); ++i) {
            if (find(duplicated.begin(), duplicated.end(), nums1[i]) == duplicated.end()) {
                results[0].emplace_back(nums1[i]);
            }
        }

        for (int i=0; i<nums2.size(); ++i) {
            if (find(duplicated.begin(), duplicated.end(), nums2[i]) == duplicated.end()) {
                results[1].emplace_back(nums2[i]);
            }
        }

        return results;
    }
};

