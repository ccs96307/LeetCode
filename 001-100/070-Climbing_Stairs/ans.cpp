class Solution {
public:
    int climbStairs(int n) {
        // Base case
        if (n == 1) {
            return 1;
        }

        // Init
        int n1 = 1;
        int n2 = 2;

        // Recursive sum 
        for (int i=2; i<n; ++i) {
            int temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }

        return n2;
    }
};

