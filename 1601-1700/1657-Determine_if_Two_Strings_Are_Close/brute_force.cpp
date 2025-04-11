class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // If their length is unsame, they are different
        if (word1.size() != word2.size()) {
            return false;
        }
        
        // Init
        unordered_map<char, int> wordCounter1;
        unordered_map<char, int> wordCounter2;
        unordered_map<int, int> appearTimes;

        // Count
        for (int i=0; i<word1.size(); ++i) {
            ++wordCounter1[word1[i]];
            ++wordCounter2[word2[i]];
        }
        
        // Match
        for (auto& it: wordCounter1) {
            if (!wordCounter2.count(it.first)) {
                return false;
            }
            
            ++appearTimes[it.second];
            --appearTimes[wordCounter2[it.first]];
        }

        // Match round 2
        for (auto& it: appearTimes) {
            if (it.second) {
                return false;
            }
        }

        return true;
    }
};

