class Solution {
public:
    bool detectCapitalUse(string word) {
        // Init
        int capNum = 0;

        // Counting capital number
        for (int i=1; i<word.size(); ++i) {
            if (isupper(word[i])) {
                ++capNum;
            }
        }
    
        return (isupper(word[0]) && capNum == word.size() - 1) || (capNum == 0);
    }
};
