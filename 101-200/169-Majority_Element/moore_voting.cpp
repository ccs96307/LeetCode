class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Init
        int major = 0;
        int count = 0;
                
        // Count
        for (auto n: nums) {
            if (count == 0) major = n;

            if (major == n) ++count;
            else --count;
        }
        
        return major;
    }
};
