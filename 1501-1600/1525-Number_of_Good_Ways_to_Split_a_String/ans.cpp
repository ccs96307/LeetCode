class Solution {
public:
    int numSplits(string s) {
        int num = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> leftCounts;
        unordered_map<int, int> rightCounts;

        for (char c: s) {
            ++rightCounts[c];

            if (rightCounts[c] == 1) {
                ++right;
            }
        }

        for (char c: s) {
            --rightCounts[c];
            if (rightCounts[c] == 0) {
                --right;
            }

            ++leftCounts[c];

            if (leftCounts[c] == 1) {
                ++left;
            }

            if (left == right) {
                ++num;
            }
        }

        return num;
    }
};
