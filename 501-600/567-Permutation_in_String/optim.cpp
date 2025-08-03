class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Base case
        if (s2.size() < s1.size()) {
            return false;
        }

        // Init
        int diff = 0;
        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);
        
        for (int i=0; i<s1.size(); ++i) {
            ++s1_count[s1[i]-'a'];
            ++s2_count[s2[i]-'a'];
        }
        
        for (int i=0; i<26; ++i) {
            if (s1_count[i] != s2_count[i]) {
                ++diff;
            }
        }

        if (diff == 0) {
            return true;
        }

        // Find the permutation
        int left = 0;
        for (int i=s1.size(); i<s2.size(); ++i) {
            int in = s2[i] - 'a';
            int out = s2[left] - 'a';

            // Out
            if (s1_count[out] == s2_count[out]) {
                ++diff;
            }
            --s2_count[out];
            if (s1_count[out] == s2_count[out]) {
                --diff;
            }

            // In
            if (s1_count[in] == s2_count[in]) {
                ++diff;
            }
            ++s2_count[in];
            if (s1_count[in] == s2_count[in]) {
                --diff;
            }

            if (diff == 0) {
                return true;
            }

            ++left;
        }

        return false;
    }
};

