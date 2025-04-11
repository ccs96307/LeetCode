class Solution {
public:
    int sumArithmeticSeq(int startN, int endN) {
        int n = endN - startN + 1;
        return startN * n + (n * (n - 1) * 1) / 2;
    }
    
    int pivotInteger(int n) {        
        for (int i=n; i>0; --i) {
            int a = sumArithmeticSeq(1, i);
            int b = sumArithmeticSeq(i, n);
            
            // If a < b, there is no answer
            if (a < b) {
                break;
            }
            
            if (a == b) {
                return i;
            }
        }
            
        return -1;
    }
};

