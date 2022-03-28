class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Init
        int len = nums.size();
        vector<vector<int>> results;
        
        // Insert the answer
        for (int i=0; i<(1<<len); ++i) {
            int k = i;
            vector<int> temp;
            
            for (int j=0; j<nums.size(); ++j) {
                if (k & 1 == 1) {
                    temp.push_back(nums[j]);
                }
                
                k = k >> 1;
            }
            
            results.push_back(temp);
        }
        
        return results;
    }
};

