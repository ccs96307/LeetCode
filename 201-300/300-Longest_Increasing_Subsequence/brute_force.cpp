class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Init
        int maxNum = 1;
        vector<int> dp(nums.size(), 0);
        dp[dp.size()-1] = 1;
               
        // Find the longest length
        for (int i=nums.size()-2; i>=0; --i) {
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    maxNum = max(dp[i], maxNum);                    
                }
            }

            if (dp[i] == 0) {
                dp[i] = 1;
            }            
        }
        
        return maxNum;
    }
};
