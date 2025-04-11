class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Init
        int si = 0;
        
        // Match
        for (int ti=0; ti<t.size(); ++ti) {
            if (s[si] == t[ti]) {
                ++si;
            }            
        }
        
        return (si == s.size());
    }
};

