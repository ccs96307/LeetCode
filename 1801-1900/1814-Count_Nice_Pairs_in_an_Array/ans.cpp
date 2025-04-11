class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        // Init
        long long total = 0;
        int mod = 1e9 + 7;
        unordered_map<int, long long> counter;

        // Count        
        for (int i=0; i<nums.size(); ++i) {
            string str_n = std::to_string(nums[i]);
            std::reverse(str_n.begin(), str_n.end());
            int diff = nums[i] - std::stoi(str_n);

            ++counter[diff];
        }

        // Accumulate
        for (auto& it: counter) {
            total = (total + (it.second * (it.second - 1) / 2)) % mod;
        }

        return total;
    }
};

