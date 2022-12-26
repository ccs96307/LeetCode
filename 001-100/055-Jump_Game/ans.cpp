class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Init
        int maxJumpPos = 0;
        int last = nums.size() - 1;
        int i = 0;

        // Reaching
        while (i <= maxJumpPos) {
            // Update `maxJumpPos`
            maxJumpPos = max(maxJumpPos, nums[i]+i);

            // If we can jump over the last element
            if (maxJumpPos >= last) {
                return true;
            }

            // Step
            ++i;
        }

        return false;
    }
};

