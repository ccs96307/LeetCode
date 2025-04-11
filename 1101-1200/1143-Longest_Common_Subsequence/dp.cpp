class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Padding
        text1 = '0' + text1;
        text2 = '1' + text2;

        // Init
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Fill in the DP table
        for (int i=1; i<text1.size(); ++i) {
            for (int j=1; j<text2.size(); ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp.back().back();
    }
};

