class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) { 
        // Base case
        if (nums.size() % 3 != 0) {
            return {};
        }
        
        // Sort
        sort(nums.begin(), nums.end());
        
        // Init
        vector<vector<int>> results;
        vector<int> result;

        // Divide
        for (int i=0; i<nums.size(); ++i) {
            result.emplace_back(nums[i]);
            
            if (result.size() == 3) {
                if (result[1] - result[0] > k || result[2] - result[1] > k || result[2] - result[0] > k) {
                    return {};
                }
                results.emplace_back(result);
                result.clear();
            }
        }
        
        return results;
    }
};
