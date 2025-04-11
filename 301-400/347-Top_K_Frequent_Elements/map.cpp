class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Init
        int maxK = 1;
        unordered_map<int, int> n2k;
        vector<int> results;
        
        // Count
        for (int n: nums) {
            ++n2k[n];            
            maxK = max(maxK, n2k[n]);
        }
        
        // Results
        while (results.size() < k) {
            for (auto& it: n2k) {
                if (it.second == maxK) {
                    results.push_back(it.first);
                }                
            }
                
            --maxK;
        }
        
        return results;
    }
};

