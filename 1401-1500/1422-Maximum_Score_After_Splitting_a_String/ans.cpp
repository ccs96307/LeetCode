class Solution {
public:
    int maxScore(string s) {
        // Init
        int length = s.size();
        int ones = 0;
        for (char& c: s) {
            if (c == '1') {
                ++ones;
            }
        }

        // Find the maximum splitting point
        int maxScore = 0;
        int currZeros = 0;
        int currOnes = 0;
        for (int i=0; i<s.size()-1; ++i) {
            if (s[i] == '0') {
                ++currZeros;
            }
            else {
                ++currOnes;
            }

            maxScore = max(maxScore, ones-currOnes+currZeros);
        }

        return maxScore;
    }
};

