class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int counts = 0;
        int sum = 0;
        vector<int> prefixCounts(k, 0);
        prefixCounts[0] = 1;

        for (int& num: nums) {
            sum = sum + num;
            int mod = ((sum % k) + k) % k;
            counts += prefixCounts[mod];
            ++prefixCounts[mod];
        }

        return counts;
    }
};

