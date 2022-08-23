class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Init
        vector<string> morse = {".-", "-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> moresExpressions;
        
        for (auto& word: words) {
            string tempMorse;
            
            for (char c: word) {
                for (char _c: morse[c-'a']) {
                    tempMorse.push_back(_c);
                }
            }
            
            moresExpressions.insert(tempMorse);
        }
        
        return moresExpressions.size();
    }
};

