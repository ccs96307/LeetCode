class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // Init
        int maxLen = -1;
        
        // For loop
        for (int left=0; left<s.size(); ++left) {
            for (int right=s.size()-1; right>=0; --right) {
                if (right - left - 1 < maxLen) {
                    break;
                }

                if (s[left] == s[right]) {
                    maxLen = max(maxLen, right - left - 1);
                }
            }
        }

        return maxLen;
    }
};

