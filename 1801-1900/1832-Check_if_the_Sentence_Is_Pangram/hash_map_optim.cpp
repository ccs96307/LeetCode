class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Base case
        if (sentence.size() < 26) return false;
        
        // Init
        unordered_map<char, bool> isExisted;        
        for (char c: sentence) {
            isExisted[c] = true;
        }
        
        // If existed character less than 26
        if (isExisted.size() < 26) {
            return false;
        }
        
        for (auto& it: isExisted) {
            if (it.second == false) {
                return false;
            }
        }
        
        return true;
    }
};
