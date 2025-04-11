class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Base case
        if (n < 1) {
            return false;
        }
        else if (n == 1) {
            return true;
        }

        // If is odd
        if (n % 2 == 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        int remainder = n % 2;
        n = n / 2 + remainder;

        return isPowerOfTwo(n);
    }
};

