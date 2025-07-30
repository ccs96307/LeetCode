class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> prefixCounts;
        prefixCounts[0] = 1;

        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];

            if (prefixCounts.count(sum - k)) {
                count += prefixCounts[sum - k];
            }

            ++prefixCounts[sum];
        }

        return count;
    }
};

