class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // Init
        int maxLen = -1;
        unordered_map<char, int> c2initPos;

        // Traversal
        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
            if (c2initPos.find(c) == c2initPos.end()) {
                c2initPos[c] = i;
            }
            else {
                maxLen = max(maxLen, i - c2initPos[c] - 1);
            }
        }

        return maxLen;
    }
};

