class Solution {
public:
    bool detectCapitalUse(string word) {
        // Base case
        if (word.size() == 1) return true;
        if (!isupper(word[0]) && isupper(word[1])) return false;
        
        for (int i=1; i<word.size()-1; ++i) {
            if (isupper(word[i]) != isupper(word[i+1])) return false;
        }
        
        return true;
    }
};

