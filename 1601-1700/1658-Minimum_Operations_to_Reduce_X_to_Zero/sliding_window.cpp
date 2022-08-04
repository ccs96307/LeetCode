class Solution {
public:    
    int minOperations(vector<int>& nums, int x) {
        // Init        
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int sum = 0;
        int max_len = 0;
        int left = 0;
        bool isFound = false;
        
        // Sliding window
        for (int right=0; right<nums.size(); ++right) {
            sum += nums[right];
            
            // If the current sum is too large, reduce it.
            while (left <= right && sum > target) {
                sum -= nums[left];
                ++left;
            }
            
            // Record the maximum length
            if (sum == target) {
                isFound = true;
                max_len = max(max_len, right-left+1);
            }
        }
        
        return isFound ? nums.size() - max_len : -1;
    }
};

