class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Init
        sort(nums.begin(), nums.end());

        // Find
        for (int i=1; i<nums.size(); i+=2) {
            if (nums[i] != nums[i-1]) return nums[i-1];
        }
        
        return nums.back();
    }
};

