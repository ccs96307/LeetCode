class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Init
        vector<vector<int>> results;

        // Sort
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); ++i) {
            // Skip the same number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int temp = nums[i] + nums[left] + nums[right];
                
                if (temp > 0) {
                    --right;
                }
                else if (temp < 0) {
                    ++left;
                }
                else {
                    results.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip the same number
                    while (left < right && nums[left] == nums[left+1]) ++left;
                    while (left < right && nums[right] == nums[right-1]) --right;

                    ++left;
                    --right;
                    
                }
            }
        }
        
        return results;
    }
};

