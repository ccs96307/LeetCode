class Solution {
public:
    bool outOfRange(char &c) {
        return (
            (c < '0' || c > '9') && 
            (c > 'z' || c < 'a') && 
            (c < 'A' || c > 'Z')
        );
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        int lowercaseDiff = 'a' - 'A';

        while (left <= right) {
            char l = s[left];
            char r = s[right];

            if (outOfRange(l)) {
                ++left;
                continue;
            }

            if (outOfRange(r)) {
                --right;
                continue;
            }

            int lDiff = l >= 'a' ? l - '0' - lowercaseDiff : l - '0';
            int rDiff = r >= 'a' ? r - '0' - lowercaseDiff : r - '0';

            if (lDiff != rDiff) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};

