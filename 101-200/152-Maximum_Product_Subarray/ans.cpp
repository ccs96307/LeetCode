class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int max_end = nums[0];
        int min_end = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            int x = nums[i];
            
            if (nums[i] < 0) {
                swap(max_end, min_end);
            }

            max_end = max(x, max_end * x);
            min_end = min(x, min_end * x);

            ans = max(ans, max_end);
        }

        return ans;
    }
};

