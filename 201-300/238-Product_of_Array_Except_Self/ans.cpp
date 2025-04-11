class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Init
        vector<int> results(nums.size(), 0);
        int zeros = 0;
        int total = 1;

        for (int& n: nums) {
            if (n == 0) {
                ++zeros;
            }
            else {
                total *= n;
            }
        }

        // If 0's > 2
        if (zeros >= 2) {
            return results;
        }
        // If 0 == 1
        else if (zeros == 1) {
            for (int i=0; i<nums.size(); ++i) {
                if (nums[i] == 0) {
                    results[i] = total;
                }
            }

            return results;
        }

        // If 0 not in nums
        for (int i=0 ; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                results[i] = total / nums[i];
            }
            else {
                results[i] = total;
            }
        }

        return results;
    }
};

