class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num2pos;

        for (int i=0; i<nums.size(); ++i) {
            if (num2pos.count(nums[i])) {
                if (i - num2pos[nums[i]] <= k) {
                    return true;
                }
            }

            num2pos[nums[i]] = i;
        }

        return false;
    }
};

