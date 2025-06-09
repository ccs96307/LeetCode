class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpS2T;
        unordered_map<char, char> mpT2S;
        for (int i=0; i<s.size(); ++i) {
            if (mpS2T.find(s[i]) == mpS2T.end() && mpT2S.find(t[i]) == mpT2S.end()) {
                mpS2T[s[i]] = t[i];
                mpT2S[t[i]] = s[i];
            }

            if (mpS2T[s[i]] != t[i] || mpT2S[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};

