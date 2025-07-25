class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int num = 0;
        unordered_map<char, vector<pair<string::iterator, string::iterator>>> waitings;

        for (string& word: words) {
            waitings[word[0]].emplace_back(word.begin(), word.end());
        }

        for (char c: s) {
            auto old_bucket = move(waitings[c]);
            waitings[c].clear();

            for (auto& [it, end] : old_bucket) {
                ++it;
                if (it == end) {
                    ++num;
                }
                else {
                    waitings[*it].emplace_back(it, end);
                }
            }
        }

        return num;
    }
};

