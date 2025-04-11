class Solution {
public:
    int romanToInt(string s) {
        // Init
        int lastNum = 0;
        int sum = 0;
        unordered_map<char, int> R2I = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        // Count
        for (int i=s.size()-1; i>=0; --i) {
            if (R2I[s[i]] >= lastNum) {
                lastNum = R2I[s[i]];
                sum += R2I[s[i]];
            }
            else {
                sum -= R2I[s[i]];
            }
        }
        
        return sum;
    }
};

