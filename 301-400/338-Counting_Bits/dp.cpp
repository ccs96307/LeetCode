class Solution {
public:
    vector<int> countBits(int n) {
        // Base case
        if (n == 0) return {0};
        
        // Init
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        
        // Count
        for (int i=2; i<=n; ++i) {
            if (i % 2 == 0) {
                dp[i] = dp[i/2];
            }
            else {
                dp[i] = dp[i/2] + 1;
            }
        }
        
        return dp;
    }
};

