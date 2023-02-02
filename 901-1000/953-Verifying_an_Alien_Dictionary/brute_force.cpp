class Solution {
public:
    bool isVerify(string& word1, string& word2, unordered_map<char, int> alienOrder) {
        for (int i=0; i<word1.size(); ++i) {
            // If word2 finished first, it means the word2 is priority!
            if (i >= word2.size()) {
                return false;
            }

            // If words have the same character,
            // continue to compare the next character
            if (word1[i] == word2[i]) {
                continue;
            }
            return alienOrder[word1[i]] < alienOrder[word2[i]];
        }
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        // Init
        int i = 0;
        
        // Max length
        int maxLen = 0;
        for (string& word: words) {
            maxLen = max(maxLen, int(word.size()));
        }

        // Alien order
        unordered_map<char, int> alienOrder;
        for (int i=0; i<order.size(); ++i) {
            alienOrder[order[i]] = i;
        }

        // Comparison
        for (int i=0; i<words.size()-1; ++i) {
            string& word1 = words[i];
            string& word2 = words[i+1];

            if (!isVerify(word1, word2, alienOrder)) {
                return false;
            }
        }

        return true;
    }
};


