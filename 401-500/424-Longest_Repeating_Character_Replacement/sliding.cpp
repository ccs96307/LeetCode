class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        int max_num = 0;
        int left = 0;
        vector<int> counts(26, 0);

        for (int right=0; right<s.size(); ++right) {
            int in = s[right] - 'A';
            ++counts[in];
            max_num = max(max_num, counts[in]);

            while ((right - left + 1) - max_num > k) {
                int out = s[left] - 'A';
                --counts[out];
                ++left;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

