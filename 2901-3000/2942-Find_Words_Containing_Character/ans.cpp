class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::vector<int> results;

        for (int i=0; i<words.size(); ++i) {
            for (char &c: words[i]) {
                if (c == x) {
                    results.emplace_back(i);
                    break;
                }
            }
        }

        return results;
    }
};

