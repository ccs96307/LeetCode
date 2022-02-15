class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Init
        int ans = 0;

        // Find
        for (int n: nums) {
            ans ^= n;
        }
        
        return ans;
    }
};

