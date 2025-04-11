class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    bool halvesAreAlike(string s) {        
        int balance = 0;
        int pivot = s.size() / 2;
                
        // Count
        for (int i=0; i<pivot; ++i) {
            if (isVowel(s[i])) {
                ++balance;
            }
            
            if (isVowel(s[i+pivot])) {
                --balance;
            }
        }
                
        return balance == 0;
    }
};

