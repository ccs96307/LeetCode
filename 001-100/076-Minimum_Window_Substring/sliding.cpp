class Solution {
public:
    string minWindow(string s, string t) {
        int min_len = INT_MAX;
        int min_idx = 0;
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for (char c: t) {
            ++need[c];
        }

        int required = int(need.size());
        int formed = 0;
        int left = 0;
        for (int right=0; right<s.size(); ++right) {
            char in = s[right];
            ++have[in];

            if (need.count(in) && have[in] == need[in]) {
                ++formed;
            }

            while (formed == required) {
                if (min_len > right - left + 1) {
                    min_len = right - left + 1;
                    min_idx = left;
                }

                char out = s[left];
                --have[out];
                if (need.count(out) && have[out] < need[out]) {
                    --formed;
                }

                ++left;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_idx, min_len);
    }
};

