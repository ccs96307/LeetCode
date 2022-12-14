class Solution {
public:    
    int rob(vector<int>& nums) {
        // Base case
        if (nums.size() == 1) {
            return nums[0];
        }

        // Init
        int maxRob = max(nums[0], nums[1]);

        // Find the best rob path
        for (int i=2; i<nums.size(); ++i) {
            if (i - 3 >= 0) {
                nums[i] += max(nums[i-2], nums[i-3]);
            }
            else {
                nums[i] += nums[i-2];
            }

            maxRob = max(maxRob, nums[i]);
        }

        return maxRob;
    }
};

