class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroNum = 0;
        int product = 1;
        vector<int> results(nums.size(), 0);
        
        for (int &num: nums) {
            if (num == 0) {
                ++zeroNum;
            }
            else {
                product *= num;
            }
        }

        if (zeroNum == 0) {
            for (int i=0; i<nums.size(); ++i) {
                results[i] = product / nums[i];
            }
        }
        else if (zeroNum == 1) {
            for (int i=0; i<nums.size(); ++i) {
                if (nums[i] == 0) {
                    results[i] = product;
                }
            }
        }

        return results;
    }
};

