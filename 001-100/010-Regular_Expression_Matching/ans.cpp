class Solution {
public:
    bool isMatch(string s, string p) {
        // Init
        int n = s.size();
        int m = p.size();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));

        // Initialize DP table
        dp[0][0] = true;
        for (int j=1; j<m; ++j) {
            if (p[j] == '*') {
                dp[0][j+1] = dp[0][j-1];
            }
        }

        // Match
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (p[j-2] == s[i-1] || p[j-2] == '.'));
                }
                else {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
                }
            }
        }

        return dp[n][m];
    }
};
