class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int max_curr = 0;
        int min_curr = 0;

        for (int& num: nums) {
            total += num;
            max_curr += num;
            max_sum = max(max_sum, max_curr);
            if (max_curr < 0) {
                max_curr = 0;
            }

            min_curr += num;
            min_sum = min(min_sum, min_curr);
            if (min_curr > 0) {
                min_curr = 0;
            }
        }

        if (max_sum < 0) {
            return max_sum;
        }

        return max(max_sum, total - min_sum);
    }
};

