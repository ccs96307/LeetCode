class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // Init
        int l = 0;
        int r = nums.size() - 1;
        
        // Two point
        while (l < r) {
            if (nums[l] % 2 == 1 && nums[r] % 2 == 0) {
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }
            
            if (nums[l] % 2 == 0) ++l;
            if (nums[r] % 2 == 1) --r;
        }
        
        return nums;
    }
};

