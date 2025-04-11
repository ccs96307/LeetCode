class Solution {
public:
    bool isPowerOfFour(int n) {     
        // Base case
        if (n > 4 && n % 4 != 0) return false;
        if (n == 1) return true;
        
        // Init
        int new_n = 1;
        
        while (n >= new_n && INT_MAX / new_n >= 4) {            
            new_n *= 4;
            
            if (n == new_n) {
                return true;
            }
        }
                
        return false;
    }
};

