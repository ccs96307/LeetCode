class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // Init
        int si = 0;
        int ci = 0;

        // Find the first '1'
        for (int i=0; i<s.size(); ++i) {
            si = i;
            if (s[i] == '1') {
                swap(s[i], s.back());
                break;
            }
        }

        // Find the other '1's
        for (int i=si; i<s.size()-1; ++i) {
            if (s[i] == '1') {
                swap(s[i], s[ci]);
                ++ci;
            }
        }

        return s;
    }
};

