class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // Init
        int n = words.size();
        std::unordered_map<char, int> char2num;

        // Counting
        for (string& word: words) {
            for (char& c: word) {
                ++char2num[c];
            }
        }

        // Determine
        for (auto& it: char2num) {
            if (it.second % n != 0) {
                return false;
            } 
        }

        return true;
    }
};

