class Solution {
public:
    int bulbSwitch(int n) {
        // Init
        int result = 0;
        int i = 1;

        // Count result
        while (i * i <= n) {
            ++result;
            ++i;
        }

        return result;
    }
};

