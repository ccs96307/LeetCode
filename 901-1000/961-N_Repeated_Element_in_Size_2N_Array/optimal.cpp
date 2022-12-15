class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Base case
        if (nums.front() == nums.back()) {
            return nums.front();
        }
        else if (nums.back() == nums[nums.size()-2]) {
            return nums.back();
        }

        // Find the repated elements
        for (int i=0; i<nums.size()-2; ++i) {
            if (nums[i] == nums[i+1] || nums[i] == nums[i+2]) {
                return nums[i];
            }
        }

        return 0; 
    }
};

