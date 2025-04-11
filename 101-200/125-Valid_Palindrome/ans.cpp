class Solution {
public:
    bool isPalindrome(string s) {
        // Normalization & Initialization
        string new_s;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                new_s += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                new_s += tolower(s[i]);
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                new_s += s[i];
            }
        }
        
        int l = 0;
        int r = new_s.size()-1;
        
        // Match
        while (l < r) {
            if (new_s[l] != new_s[r]) return false;
            ++l;
            --r;
        }
        
        return true;
    }
};

