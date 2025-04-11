class Solution {
public:
    int longestValidParentheses(string s) {
        // Init
        int max_len = 0;
        int left = 0;
        int right = 0;

        // Left to right
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            }
            else {
                ++right;
            }

            if (left == right) {
                max_len = max(max_len, left+right);
            }
            else if (left < right) {
                left = 0;
                right = 0;
            }
        }

        // Init
        left = 0;
        right = 0;

        // Right to left
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == ')') {
                ++right;
            }
            else {
                ++left;
            }

            if (left == right) {
                max_len = max(max_len, left+right);
            }
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return max_len;
    }
};