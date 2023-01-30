class Solution {
public:
    int tribonacci(int n) {
        // Init
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        int tn = 0;

        // Base case
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return t0 + t1;
        }

        // Recursion
        for (int i=3; i<=n; ++i) {
            tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }

        return tn;
    }
};

