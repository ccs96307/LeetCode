class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPos = 0;
        int nonZeroPos = 0;

        while (nonZeroPos < nums.size() && zeroPos < nums.size()) {
            if (nonZeroPos <= zeroPos) {
                ++nonZeroPos;
            }
            else if (nums[nonZeroPos] == 0) {
                ++nonZeroPos;
            }
            else if (nums[zeroPos] != 0) {
                ++zeroPos;
            }
            else if (nums[zeroPos] == 0 && nums[nonZeroPos] != 0) {
                std::swap(nums[zeroPos], nums[nonZeroPos]);
                ++zeroPos;
                ++nonZeroPos;
            }
        }
    }
};

