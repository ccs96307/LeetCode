class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int diff = 0;
        int left = 0;
        int longest = 0;
        unordered_map<int, int> counts;

        for (int i=0; i<s.size(); ++i) {
            if (counts[s[i]] == 1) {
                ++diff;
            } 
            ++counts[s[i]];

            while (diff > 0) {
                --counts[s[left]];
                if (counts[s[left]] == 1) {
                    --diff;
                }
                ++left;
            }

            longest = max(longest, i - left + 1);
        }

        return longest;
    }
};

