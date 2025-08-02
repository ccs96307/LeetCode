class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_length = 0;
        int sum = 0;
        unordered_map<int, int> prefix;
        prefix[0] = -1;

        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            int diff = i + 1 - sum * 2;

            auto it = prefix.find(diff);
            if (it == prefix.end()) {
                prefix[diff] = i;
            }
            else {
                max_length = max(max_length, i - prefix[diff]);
            }
        }

        return max_length;
    }
};

