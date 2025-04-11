class Solution {
public:
    string largestOddNumber(string num) {
        // Init
        int tail = 0;
        unordered_map<char, bool> isEven({
            {'0', true},
            {'2', true},
            {'4', true},
            {'6', true},
            {'8', true},
        });

        // Count from the tail
        for (int i=num.size()-1; i>=0; --i) {
            if (!isEven[num[i]]) {
                tail = i + 1;
                break;
            }
        }

        return num.substr(0, tail);
    }
};

