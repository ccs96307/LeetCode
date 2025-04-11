class Solution {
public:    
    bool matching(string& s, int left, int right, int count) {
        // Base case
        if (count > 1) return false;
        
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            }
            else {
                return (matching(s, left+1, right, count+1) || matching(s, left, right-1, count+1));
            }
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        // Init
        int left = 0;
        int right = s.size() - 1;
        
        // Matching
        return matching(s, left, right, 0);
    }
};

