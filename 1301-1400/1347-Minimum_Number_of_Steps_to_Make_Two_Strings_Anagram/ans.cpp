class Solution {
public:
    int minSteps(string s, string t) {
        // Init
        int diff = 0;
        vector<int> diffs(26, 0);

        // Count
        for (int i=0; i<s.size(); ++i) {
            ++diffs[s[i]-'a'];
            --diffs[t[i]-'a'];
        }

        // Compute `diff`
        for (int i=0; i<26; ++i) {
            diff += abs(diffs[i]);
        }

        return diff >> 1;
    }
};

