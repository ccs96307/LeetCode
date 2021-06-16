class Solution {
public:
    int divide(int dividend, int divisor) {
        long zero = 0;
        long q = 0;
        
        if (divisor == 1) {
            q = dividend;
        }
        else if (divisor == -1) {
            q = zero-dividend;
        }
        else if (dividend >= 0 && divisor >= 0) { 
            while (dividend >= divisor) {
                dividend -= divisor;
                q++;
            }
        }
        else if (dividend >= 0 && divisor <= 0) {
            while (dividend >= zero-divisor) {
                dividend += divisor;
                q--;
            }
        }
        else if (dividend <= 0 && divisor >= 0) {
            while (dividend <= zero-divisor) {
                dividend += divisor;
                q--;
            }
        }
        else if (dividend <= 0 && divisor <= 0) {
            while (dividend <= divisor) {
                dividend -= divisor;
                q++;
            }
        }
        
        if (q >= INT_MAX) return INT_MAX;
        else if (q <= INT_MIN) return INT_MIN;
        return q;
    }
};

