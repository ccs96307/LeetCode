class Solution {
public:
    bool rotateString(string s, string goal) {
        // Base case
        if (s.size() != goal.size()) {
            return false;
        }
        
        // Init
        bool isSame = true;
        for (int i=0; i<s.size(); ++i) {
            // If the begin of string is unsame
            if (s[i] != goal[0]) {
                continue;
            }
            
            // Matching
            isSame = true;
            for (int j=1; j<s.size(); ++j) {
                int si = (i + j) % s.size();
                                
                if (s[si] != goal[j]) {
                    isSame = false;
                    break;
                }
            }
            
            if (isSame) {
                return true;
            }
        }
        
        return false;
    }
};

