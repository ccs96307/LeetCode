class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // Init
        int ans = 0;
        unordered_map<int, int> cache;
        
        // nums1 and nums2
        for (int n1: nums1) {
            for (int n2: nums2) {
                ++cache[n1+n2];
            }
        }
        
        // nums3 and nums4
        for (int n3: nums3) {
            for (int n4: nums4) {
                ans += cache[-(n3+n4)];
            }
        }
        
        return ans;
    }
};
