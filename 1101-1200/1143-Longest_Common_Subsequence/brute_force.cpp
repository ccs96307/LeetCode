class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Set the `text1` is always the longer one
        if (text2.size() > text1.size()) {
            swap(text1, text2);
        }

        // Init
        int longest = 0;
        vector<int> dp(text2.size()+1, 0);
        unordered_map<char, vector<int>> char2pos;
        for (int i=0; i<text2.size(); ++i) {
            char2pos[text2[i]].emplace_back(i+1);
        }

        // Matching
        for (int i=0; i<text1.size(); ++i) {
            if (char2pos.find(text1[i]) == char2pos.end()) {
                continue;
            }

            for (int k=char2pos[text1[i]].size()-1; k>=0; --k) {
                int idx = char2pos[text1[i]][k];
                int temp = 0;
                for (int j=0; j<idx; ++j) {
                    temp = max(temp, dp[j]+1);
                }
                dp[idx] = temp;
                longest = max(longest, dp[idx]);
            }
        }

        return longest;
    }
};

