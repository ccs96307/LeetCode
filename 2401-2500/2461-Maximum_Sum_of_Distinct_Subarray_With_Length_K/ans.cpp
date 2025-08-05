class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0;
        long long temp = 0;
        int diff = 0;
        unordered_map<int, int> counts; 

        for (int i=0; i<k; ++i) {
            temp += nums[i];
            ++counts[nums[i]];

            if (counts[nums[i]] == 2) {
                ++diff;
            }
        }

        if (diff == 0) {
            result = temp;
        }

        int s = 0;
        for (int i=k; i<nums.size(); ++i) {
            temp += nums[i];
            temp -= nums[s];

            ++counts[nums[i]];
            if (counts[nums[i]] == 2) {
                ++diff;
            }

            --counts[nums[s]];
            if (counts[nums[s]] == 1) {
                --diff;
            }

            if (diff == 0) {
                result = max(result, temp);
            }

            ++s;
        }

        return result;
    }
};

