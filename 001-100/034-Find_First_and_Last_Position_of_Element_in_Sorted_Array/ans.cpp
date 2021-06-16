class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_p = -1;
        int last_p = -1;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == target) {
                last_p = i;
                if (first_p == -1) {
                    first_p = i;
                } 
            }
        }
        
        return {first_p, last_p};
    }
};

