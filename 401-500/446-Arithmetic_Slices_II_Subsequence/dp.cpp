class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // Init
        int results = 0;
        vector<unordered_map<int, int>> dp(nums.size());
        
        // Count
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<i; ++j) {
                // 32 bit limit
                long longDiff = (long)nums[i] - nums[j];
                if (longDiff > INT_MAX || longDiff < INT_MIN) {
                    continue;
                }
                
                // Records
                int intDiff = (int)longDiff;
                ++dp[i][intDiff];
                
                if (dp[j].count(intDiff)) {
                    results += dp[j][intDiff];
                    dp[i][intDiff] += dp[j][intDiff];
                }
            }
        }
        
        return results;
    }
};

