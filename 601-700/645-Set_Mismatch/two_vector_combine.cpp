class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Init
        vector<int> duplicated;
        vector<int> lack;
        unordered_map<int, int> numAmount;
        
        // Build
        for (int& num: nums) {
           ++numAmount[num];
        }
        
        // Find
        for (int i=1; i<=nums.size(); ++i) {
            if (numAmount[i] == 0) {
                lack.push_back(i);
            }
            else if (numAmount[i] > 1) {
                duplicated.push_back(i);
            }
        }
        
        // Combine
        duplicated.insert(duplicated.end(), lack.begin(), lack.end());
        
        return duplicated;
    }
};

