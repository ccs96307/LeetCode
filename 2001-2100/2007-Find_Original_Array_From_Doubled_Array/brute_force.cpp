class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // Base case
        if (changed.size() % 2 == 1) {
            return {};
        }
        
        // Sort
        sort(changed.begin(), changed.end());
        
        // Init
        vector<int> results;
        unordered_map<int, int> isNeed;
        
        for (int i=0; i<changed.size(); ++i) {
            if (isNeed[changed[i]] == 0) {
                ++isNeed[changed[i]*2];
            }
            else {
                --isNeed[changed[i]];
                results.push_back(changed[i]/2);
            }
        }
        
        return (results.size()==changed.size()/2) 
            ? results 
            : vector<int>();
    }
};

