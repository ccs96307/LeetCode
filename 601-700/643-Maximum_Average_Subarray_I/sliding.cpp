class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        long long best = 0;
        for (int i=0; i<k; ++i) {
            sum += nums[i];
        }
        best = sum;
        
        int left = 0;
        for (int i=k; i<nums.size(); ++i) {
            sum = sum - nums[left] + nums[i];
            best = max(best, sum);
            ++left;
        }

        return static_cast<double>(best) / k;
    }
};

