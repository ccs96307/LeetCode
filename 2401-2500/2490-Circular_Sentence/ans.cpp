class Solution {
public:
    bool isCircularSentence(string sentence) {
        // The first & last characters
        if (sentence.front() != sentence.back()) {
            return false;
        }
        
        // Init
        for (int i=0; i<sentence.size(); ++i) {        
            if (sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) {
                return false;
            }
        }
        
        return true;
    }
};

