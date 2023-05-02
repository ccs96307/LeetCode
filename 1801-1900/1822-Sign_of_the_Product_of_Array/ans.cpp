class Solution {
public:
    int arraySign(vector<int>& nums) {
        // Init
        int neg = 0;

        // Count the `neg` number
        for (int& num: nums) {
            if (num < 0) {
                ++neg;
            }
            else if (num == 0) {
                return 0;
            }
        }

        // If `neg` is odd, return -1; else return 1 
        return neg % 2 ? -1 : 1;
    }
};

