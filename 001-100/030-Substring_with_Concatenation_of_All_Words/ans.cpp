class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return results;

        unordered_map<string_view, int> wordFreq;
        for (string& w : words) ++wordFreq[w];

        for (int offset = 0; offset < wordLen; ++offset) {
            unordered_map<string_view, int> windowCount;
            int count = 0;
            for (int left = offset, right = offset; right + wordLen <= s.size(); right += wordLen) {
                string_view word = string_view(s).substr(right, wordLen);
                if (wordFreq.count(word)) {
                    ++windowCount[word];
                    ++count;

                    while (windowCount[word] > wordFreq[word]) {
                        string_view out = string_view(s).substr(left, wordLen);
                        --windowCount[out];
                        --count;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        results.emplace_back(left);
                    }
                } else {
                    windowCount.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return results;
    }
};
