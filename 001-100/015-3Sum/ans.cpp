class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Preventation
        if (nums.size() <= 2) return {};
        
        // Sort
        sort(nums.begin(), nums.end());
                        
        // Init
        vector<vector<int>> results;
        int target = 0;
        
        // Find the match ans
        for (int i=0; i<nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1;
            int right = nums.size()-1;
            
            while (left < right) {
                if (left > i+1 && right < nums.size()-1) {
                    if (nums[left] == nums[left-1] && nums[right] == nums[right+1]) {
                        ++left;
                        --right;
                        continue;
                    }
                }
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    results.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;                    
                }
                else if (sum < 0) {
                    ++left;
                }
                else if (sum > 0) {
                    --right;
                }
            }
        }
        
        return results;
    }
};

