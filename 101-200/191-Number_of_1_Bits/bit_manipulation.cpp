class Solution {
public:
    int hammingWeight(int n) {
        int weight = 0;

        while (n > 0) {
            if (n % 2 == 1) {
                ++weight;
            }

            n >>= 1;
        }

        return weight;
    }
};

