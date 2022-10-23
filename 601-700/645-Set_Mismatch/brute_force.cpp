class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Init
        vector<int> errorNums;
        unordered_map<int, int> numAmount;
        
        // Build
        for (int& num: nums) {
           ++numAmount[num];
        }
        
        // Duplicated
        for (auto& it: numAmount) {
            if (it.second > 1) {
                errorNums.push_back(it.first);
            }
        }
        
        // Lack
        for (int i=1; i<=nums.size(); ++i) {
            if (numAmount[i] == 0) {
                errorNums.push_back(i);
            }
        }
        
        return errorNums;
    }
};

