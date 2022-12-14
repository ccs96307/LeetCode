class Solution {
public:    
    int rob(vector<int>& nums) {
        // Base case
        if (nums.size() >= 3) {
            nums[2] += nums[0];
        }
        else if (nums.size() == 1) {
            return nums[0];
        }

        // Find the best rob path
        for (int i=3; i<nums.size(); ++i) {
            nums[i] += max(nums[i-2], nums[i-3]);
        }

        return max(nums[nums.size()-2], nums.back());
    }
};

