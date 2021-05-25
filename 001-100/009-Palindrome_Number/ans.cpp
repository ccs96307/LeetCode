class Solution {
public:
    bool isPalindrome(int x) {
        // Preventation
        if (x < 0) return false;

        // Init
        long int x_reverse = 0;
        int x_origin = x;
        
        // Calculate reverse value
        while (x) {
            x_reverse = x_reverse*10 + x%10;
            x /= 10;
        }
        
        return x_origin == x_reverse;
    }
};
