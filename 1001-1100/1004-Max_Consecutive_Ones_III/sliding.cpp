class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = 0;
        int zero_num = 0;
        int left = 0;

        for (int right=0; right<nums.size(); ++right) {
            if (nums[right] == 0) {
                ++zero_num;
            }

            while (zero_num > k) {
                if (nums[left] == 0) {
                    --zero_num;
                }
                ++left;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

