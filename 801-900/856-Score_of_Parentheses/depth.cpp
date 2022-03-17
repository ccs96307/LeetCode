class Solution {
public:
    int scoreOfParentheses(string s) {
        // Init
        int depth = 0;
        int score = 0;
        bool needCount = false;
        
        // Traversal
        for (auto& c: s) {
            if (c == '(') {
                ++depth;
                needCount = true;
            }
            else {
                --depth;
                
                if (needCount) {
                    score += pow(2, depth);
                }
                
                needCount = false;
            }            
        }
        
        return score;
    }
};

