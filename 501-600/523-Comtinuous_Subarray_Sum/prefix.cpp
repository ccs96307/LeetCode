class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> first;
        first[0] = -1;

        long long sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            int mod = (int)(sum % k);
            
            auto it = first.find(mod);
            if (it != first.end()) {
                if (i - it->second >= 2) {
                    return true;
                }
            } else {
                first[mod] = i;
            }
        }
        return false;
    }
};

