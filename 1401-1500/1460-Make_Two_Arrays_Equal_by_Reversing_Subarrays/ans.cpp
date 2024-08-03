class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Init
        unordered_map<int, int> mp;

        // Creating map
        for (int i=0; i<target.size(); ++i) {
            ++mp[target[i]];
            --mp[arr[i]];
        }

        // Check the element in the mp is 0
        for (auto& it: mp) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};

