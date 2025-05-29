class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] - 1 < nums.size() && nums[nums[i]-1] != nums[i]) {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }

        for (int i=1; i<=nums.size(); ++i) {
            if (nums[i-1] != i) {
                return i;
            }
        }

        return nums.size() + 1;
    }
};

