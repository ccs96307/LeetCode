class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // Sort
        sort(tokens.begin(), tokens.end());
        
        // Init
        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int max_score = 0;
        
        // Count
        while (left <= right) {
            if (tokens[left] <= power) {
                power -= tokens[left];
                ++score;
                ++left;
                
                max_score = max(max_score, score);
            }
            else if (score >= 1) {
                power += tokens[right];
                --score;
                --right;
            }
            else {
                break;
            }
        }
        
        return max_score;
    }
};




