class Solution {
public:
    string getSmallestString(int n, int k) {
        // Init
        string s(n, 'a');
        int i = s.size() - 1;
        
        // Distance
        k -= n;
        
        // Matching the target string
        while (k != 0) {
            if (k > 25) {
                s[i] = 'z';
                k -= 25;
            }
            else {
                s[i] = k + 'a';
                k = 0;
            }
            
            --i;
        }
        
        return s;
    }
};

