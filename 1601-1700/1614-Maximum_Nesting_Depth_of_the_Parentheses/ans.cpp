class Solution {
public:
    int maxDepth(string s) {
        int left = 0;
        int _max = 0;

        for (char& c: s) {
            if (c == '(') {
                ++left;
            }
            else if (c == ')') {
                _max = max(_max, left);
                --left;
            }
        }

        return _max;
    }
};

