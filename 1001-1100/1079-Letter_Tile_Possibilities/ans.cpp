class Solution {
public:
    void DFS(unordered_map<char, int>& char2times, int& count) {
        for (const auto& [c, times] : char2times) {
            if (times == 0) {
                continue;
            }

            // Recursive
            --char2times[c];
            ++count;
            DFS(char2times, count);

            // Recovery
            ++char2times[c];
        }
    }

    int numTilePossibilities(string tiles) {
        // Init
        int count = 0;
        std::unordered_map<char, int> char2times;
        for (char& c: tiles) {
            ++char2times[c];
        }

        DFS(char2times, count);

        return count;
    }
};

