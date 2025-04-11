class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // Init
        vector<int> shuffleNums;
        
        // Shuffle
        for (int i=0; i<n; ++i) {
            shuffleNums.emplace_back(nums[i]);
            shuffleNums.emplace_back(nums[n+i]);
        }

        return shuffleNums;
    }
};

