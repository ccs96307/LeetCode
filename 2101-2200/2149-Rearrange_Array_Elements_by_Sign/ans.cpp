class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int pi = 0;
        int ni = 0;
        int times = nums.size() / 2;

        for (int t=0; t<times; ++t) {
            for (int i=pi; i<nums.size(); ++i) {
                if (nums[i] > 0) {
                    ans.push_back(nums[i]);
                    pi = i+1;
                    break;
                }
            }
            
            for (int i=ni; i<nums.size(); ++i) {
                if (nums[i] < 0) {
                    ans.push_back(nums[i]);
                    ni = i+1;
                    break;
                }
            }
        }
        
        return ans;
    }
};
