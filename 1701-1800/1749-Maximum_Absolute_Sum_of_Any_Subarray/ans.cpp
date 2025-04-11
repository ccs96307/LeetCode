class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Find the maximum and minimum
        int _max = 0;
        int _min = 0;
        int _currMax = 0;
        int _currMin = 0;

        for (int num: nums) {
            _currMax = max(_currMax + num, 0);
            _currMin = min(_currMin + num, 0);

            _max = max(_currMax, _max);
            _min = min(_currMin, _min);
        }

        return max(_max, std::abs(_min));
    }
};

