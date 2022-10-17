class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Base case
        if (sentence.size() < 26) return false;
        
        // Init
        unordered_map<char, bool> isExisted;
        for (int i='a'; i<='z'; ++i) {
            isExisted[i] = false;
        }
        
        for (char c: sentence) {
            isExisted[c] = true;
        }
        
        for (auto& it: isExisted) {
            if (it.second == false) {
                return false;
            }
        }
        
        return true;
    }
};

