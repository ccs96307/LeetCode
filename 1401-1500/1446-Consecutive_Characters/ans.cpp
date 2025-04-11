class Solution {
public:
    int maxPower(string s) {
        // Init
        int n = 1;
        int temp_n = 1;
        
        // Match
        for (int i=1; i<s.size(); ++i) {
            if (s[i] == s[i-1]) {
                ++temp_n;
            }
            else {
                temp_n = 1;
            }
            
            // Max
            n = max(n, temp_n);
        }
        
        return n;
    }
};

