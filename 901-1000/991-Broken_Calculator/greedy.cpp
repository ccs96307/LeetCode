class Solution {
public:
    int brokenCalc(int startValue, int target) {        
        // Init
        int opt = 0;
        
        while (startValue < target) {
            if (target % 2 == 1) {
                ++target;
            }
            else {
                target /= 2;
            }
            
            // Step
            ++opt;
        }
        
        return opt + startValue - target;
    }
};

