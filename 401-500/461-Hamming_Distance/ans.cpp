class Solution {
public:
    int hammingDistance(int x, int y) {
        // Init
        int max_n = 2;
        int d = 0;
        
        // Count max n
        while (true) {
            if (x >= max_n || y >= max_n) {
                if (max_n <= INT_MAX-max_n) max_n = max_n * 2;
                else break;
            }
            else {
                break;
            }
        }
        
        // Create binary expressions
        while (true) {
            if (x >= max_n && y >= max_n) {
                x -= max_n;
                y -= max_n;
            }
            else if (x >= max_n && y < max_n){
                d += 1;
                x -= max_n;
            }
            else if (x < max_n && y >= max_n) {
                d += 1;
                y -= max_n;
            }
            
            max_n /= 2;
            if (max_n == 1) break;
        }
        
        if (x != y) ++d;
        
        return d;
    }
};
