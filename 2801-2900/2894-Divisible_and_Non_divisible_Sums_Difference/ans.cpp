class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;

        for (int i=1; i<=n; ++i) {
            if (i % m) {
                num1 += i;
            }
            else {
                num2 += i;
            }
        }

        return num1 - num2;
    }
};

