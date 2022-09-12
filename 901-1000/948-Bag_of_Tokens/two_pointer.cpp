class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // Sort
        sort(tokens.begin(), tokens.end());
        
        // Init
        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int over_get = 0;
        
        // Count
        while (left <= right) {
            if (tokens[left] <= power) {
                power -= tokens[left];
                ++score;
                ++left;
                over_get = 0;
            }
            else if (score >= 1) {
                power += tokens[right];
                --score;
                --right;
                ++over_get;
            }
            else {
                break;
            }
        }
        
        return score+over_get;
    }
};

