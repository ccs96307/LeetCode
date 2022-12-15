class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int& n: nums) {
            if (mp[n]) {
                return n;
            }

            mp[n] = true;
        }

        return 0; 
    }
};

