class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort
        sort(nums.begin(), nums.end());
                
        // Compute
        for (int i=nums.size()-1; i-2>=0; --i) {
            if (nums[i] < nums[i-1] + nums[i-2]) {
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }
        
        return 0;
    }
};
