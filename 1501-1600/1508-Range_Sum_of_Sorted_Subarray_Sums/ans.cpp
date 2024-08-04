class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Init
        long total = 0;
        long mod = std::pow(10, 9) + 7;
        std::vector<int> arr;

        // Count
        for (int i=0; i<nums.size(); ++i) {
            int num = 0;

            for (int j=i; j<nums.size(); ++j) {
                num += nums[j];
                arr.emplace_back(num);
            }
        }

        // Sort
        std::sort(arr.begin(), arr.end());

        // Accumulate
        for (int i=left-1; i<right; ++i) {
            total += arr[i];
            total %= mod;
        }
        return total;
    }
};
