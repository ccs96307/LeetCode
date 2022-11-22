class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) {
            n /= 4;
        }
        
        if (n % 8 == 7) {
            return 4;
        }
        
        for (int i=0; i*i<n; ++i) {
            int j = sqrt(n-i*i);
            if (i*i + j*j == n) {
                return !!i + !!j;
            }
        }
        
        return 3;
    }
};

