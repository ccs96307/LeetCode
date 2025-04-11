class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        // Init
        int count = 0;

        // Count
        for (int num=low; num<=high; ++num) {
            if (num < 10 || (num >= 100 && num <= 999)) {
                continue;
            }

            if (num < 100) {
                if (num % 11 == 0) {
                    ++count;
                }
            }
            else if (num >= 1000) {
                int a = num % 10;
                int b = num / 10 % 10;
                int c = num / 100 % 10;
                int d = num / 1000;

                if (a + b == c + d) {
                    ++count;
                }
            }
        }

        return count;
    }
};

