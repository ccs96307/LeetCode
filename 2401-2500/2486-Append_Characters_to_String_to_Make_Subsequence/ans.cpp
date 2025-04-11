class Solution {
public:
    int appendCharacters(string s, string t) {
        // Init
        int si = 0;
        int ti = 0;
        
        // Find the same characters
        while (si < s.size()) {
            if (ti < t.size() && s[si] == t[ti]) {
                ++ti;
            }
            
            ++si;
        }
        
        // Return the character numbers that need to appending
        return t.size() - ti;
    }
};

