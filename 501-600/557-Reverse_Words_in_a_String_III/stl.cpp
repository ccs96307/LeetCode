class Solution {
public:
    string reverseWords(string s) {
        // Init
        int _s = 0;
        int _e = 0;
        
        // Find space or endpoint
        while (_e <= s.size()) {
            if (_e < s.size() && s[_e] != ' ') {
                ++_e;
            }
            else {
                reverse(&s[_s], &s[_e]);
                ++_e;
                _s = _e;                
            }
        }
        
        return s;
    }
};
