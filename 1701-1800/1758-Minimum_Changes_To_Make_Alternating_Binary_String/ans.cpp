class Solution {
public:
    int minOperations(string s) {
        int odd = 0;
        int even = 0;

        for (int i=0; i<s.size(); ++i) {
            if (i % 2) {
                if (s[i] == '1') {
                    ++odd;
                }
                else {
                    ++even;
                }
            }
            else {
                if (s[i] == '1') {
                    ++even;
                }
                else {
                    ++odd;
                }
            }
        }

        return std::min(odd, even);
    }
};

