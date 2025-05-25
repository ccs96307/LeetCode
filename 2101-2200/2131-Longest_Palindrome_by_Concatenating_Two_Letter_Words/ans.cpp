class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int length = 0;
        std::unordered_map<std::string, int> count;
        
        for (std::string word: words) {
            std::string rev = word;
            reverse(rev.begin(), rev.end());

            if (count[rev] > 0) {
                length += word.size() * 2;
                --count[rev];
            }
            else {
                ++count[word];
            }
        }

        int longestSelfPalindrome = 0;
        for (const auto& [word, num]: count) {
            if (num > 0) {
                std::string rev = word;
                reverse(rev.begin(), rev.end());
                if (rev == word) {
                    longestSelfPalindrome = max(longestSelfPalindrome, static_cast<int>(word.size()));
                }
            }
        }

        length += longestSelfPalindrome;

        return length;
    }
};

