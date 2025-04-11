class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Init
        int min_v = 101;
        int min_p = -1;
        int p = -1;

        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                p = i;

                // Find the min_p
                for (int j=p+1; j<nums.size(); j++) {
                    if (nums[i] < nums[j] && nums[j] < min_v) {
                        min_p = j;
                        min_v = nums[j];
                    }
                }
                break;
            }
        }

        // Have next permutation
        if (p != -1) {
            swap(nums[p], nums[min_p]);
            sort(nums.begin()+p+1, nums.end());
        }
        else {
            sort(nums.begin(), nums.end());
        }
    }
};