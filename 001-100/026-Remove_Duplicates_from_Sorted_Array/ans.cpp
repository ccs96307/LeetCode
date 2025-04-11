class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Init
        int index = 0;

        // Walk
        for (int i=0; i<nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i-1]) {
                nums[index] = nums[i];
                ++index;
            }
        }

        return index;
    }
};