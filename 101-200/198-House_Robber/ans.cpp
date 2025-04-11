class Solution {
public:
    int rob(vector<int>& nums) {
        // Base case
        if (nums.size() == 1) {
            return nums[0];
        }

        // Init
        nums[1] = max(nums[0], nums[1]);

        // Robbing
        for (int i=2; i<nums.size(); ++i) {
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }

        return max(nums[nums.size()-1], nums[nums.size()-2]);
    }
};
