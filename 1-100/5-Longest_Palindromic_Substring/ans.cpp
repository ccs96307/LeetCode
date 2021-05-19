class Solution {
public:    
    string longestPalindrome(string s) {
        // Preventation
        if (s.size() <= 1) {
            return s;
        }
        
        // Init
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        string max_sub_str;
        max_sub_str += s[0];
        
        // Diagonal
        for (int i=0; i<n; i++) dp[i][i] = true;
        
        // Complete the DP table
        for (int i=n-2; i>=0; i--) {
            for (int j=i+1; j<n; j++) {
                if (s[i] == s[j]) {
                    if (j-i == 1 or dp[i+1][j-1] == true) {
                        dp[i][j] = true;
                        if (max_sub_str.size() < j-i+1) {
                            max_sub_str = s.substr(i, j-i+1);
                        }
                    }
                }
            }
        }
        
        return max_sub_str;
    }
};
