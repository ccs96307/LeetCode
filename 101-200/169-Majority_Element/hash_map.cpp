class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Init
        int major = 0;
        unordered_map<int, int> mp;
        
        // Count
        for (auto n: nums) {
            ++mp[n];
            
            if (mp[n] > nums.size()/2) {
                major = n;
                break;
            }
        }
        
        return major;
    }
};
