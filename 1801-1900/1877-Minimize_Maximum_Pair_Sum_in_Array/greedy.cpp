class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Init
        int _min = 0;
        
        // Sort
        sort(nums.begin(), nums.end());

        // Two point
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            _min = max(_min, nums[left] + nums[right]);
            ++left;
            --right;
        }

        return _min;
    }
};

