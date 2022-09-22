class Solution {
public:
    void reverseSubstring(int _s, int _e, string& s) {
        while (_s <= _e) {
            swap(s[_s], s[_e]);
            ++_s;
            --_e;
        }
    }
    
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
                reverseSubstring(_s, _e-1, s);
                ++_e;
                _s = _e;                
            }
        }
        
        return s;
    }
};

