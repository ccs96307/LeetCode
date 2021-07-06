class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0) return 1;
        if (x == 0) return 0;
        
        if (n < 0) return 1.0 / myPow(x, -n);
        else if (n == 1) return x;
        else {
            double temp_x = myPow(x, n/2);
            if (n % 2 == 1) return x * temp_x * temp_x;
            else return temp_x * temp_x;
        }
    }
};

