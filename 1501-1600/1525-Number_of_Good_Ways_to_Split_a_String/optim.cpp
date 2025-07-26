class Solution {
public:
    int numSplits(string s) {
        int num = 0;
        int leftUnique = 0;
        int rightUnique = 0;
        int leftCounts[26] = {0};
        int rightCounts[26] = {0};

        for (char c: s) {
            ++rightCounts[c-'a'];

            if (rightCounts[c-'a'] == 1) {
                ++rightUnique;
            }
        }

        for (char c: s) {
            --rightCounts[c-'a'];
            if (rightCounts[c-'a'] == 0) {
                --rightUnique;
            }

            ++leftCounts[c-'a'];

            if (leftCounts[c-'a'] == 1) {
                ++leftUnique;
            }

            if (leftUnique == rightUnique) {
                ++num;
            }
        }

        return num;
    }
};
