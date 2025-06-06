class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count = {
            {'b', 0},
            {'a', 0},
            {'l', 0},
            {'o', 0},
            {'n', 0},
        };

        for (char &c: text) {
            if (count.find(c) != count.end()) {
                ++count[c];
            }
        }

        count['l'] /= 2;
        count['o'] /= 2;

        int minNum = INT_MAX;

        for (auto& [ c, num ] : count) {
            minNum = min(minNum, num);
        }

        return minNum;
    }
};

