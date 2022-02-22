class Solution {
public:
    int titleToNumber(string columnTitle) {
        // Init
        int ans = 0;
        
        // Count ('A' = 65)
        for (auto t: columnTitle) {
            ans *= 26;
            ans += t - 64;
        }
        
        return ans;
    }
};

