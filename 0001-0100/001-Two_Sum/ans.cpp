class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Init
        vector<int> lack;
        
        // Find
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<lack.size(); ++j) {
                if (nums[i] == lack[j]) {
                    return {j, i};
                }
            }
            
            // add to lack
            lack.push_back(target-nums[i]);
        }
        
        return {};
    }
};
