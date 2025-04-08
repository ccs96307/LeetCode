class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Init
        std::unordered_set<int> exists;

        // Count remainLength
        for (int i=nums.size()-1; i>=0; --i) {
            if (exists.find(nums[i]) != exists.end()) {
                break;
            }

            exists.insert(nums[i]);
        }

        int deleteLength = nums.size() - exists.size();

        // Special case
        if (deleteLength == 0) {
            return 0;
        }

        // Trick
        return (deleteLength + 2) / 3;
    }
};

