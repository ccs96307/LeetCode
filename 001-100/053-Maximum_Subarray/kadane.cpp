class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int result = INT_MIN;

        for (int& num: nums) {
            curr += num;
            result = max(result, curr);
            
            if (curr < 0) {
                curr = 0;
            }
        }

        return result;
    }
};

