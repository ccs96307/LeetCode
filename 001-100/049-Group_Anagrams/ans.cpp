class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Init
        std::vector<int> key;
        std::vector<vector<int>> keys;
        std::vector<vector<string>> values;
        
        // Find
        for (int i=0; i<strs.size(); ++i) {
            for (int j=0; j<strs[i].size(); ++j) {
                key.push_back(int(strs[i][j]));
            }
            
            // Sort
            sort(key.begin(), key.end());            
            vector<vector<int>>::iterator p = std::find(keys.begin(), keys.end(), key);
            
            // Exist
            if (p != keys.end()) {
                values[std::distance(keys.begin(), p)].push_back(strs[i]);
            }
            // Doesn't exist
            else {
                keys.push_back({key});
                values.push_back({strs[i]});
            }
            
            // Clear
            key.clear();
        }
        
        // Return
        return values;
    }
};
