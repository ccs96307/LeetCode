class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // Init
        long long results = 0;
        long long accum = 1;

        // Accumulate
        for (int num: nums) {
            if (num == 0) {
                results += accum;
                ++accum;
            }
            else {
                accum = 1;
            }
        }

        return results;
    }
};

