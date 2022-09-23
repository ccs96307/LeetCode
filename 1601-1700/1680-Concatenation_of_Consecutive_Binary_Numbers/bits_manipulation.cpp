class Solution {
public:
    int getBitsLen(int _i) {
        int _len = 0;
        for (int i=_i; _i>0; _i>>=1) {
            ++_len;
        }
        
        return _len;
    }
    
    int concatenatedBinary(int n) {
        // Init
        int _mod = 1e9 + 7;
        long _sum = 0;
        
        for (int i=1; i<=n; ++i) {
            _sum = ((_sum << getBitsLen(i) % _mod) + i) % _mod;
        }
        
        return _sum;
    }
};

