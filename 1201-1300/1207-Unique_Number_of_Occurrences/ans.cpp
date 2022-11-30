class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Init
        unordered_map<int, bool> occurMap;
        unordered_map<int, int> num2occur;
        
        // Count
        for (int& n: arr) {
            ++num2occur[n];
        }
        
        // Check if collison
        for (auto& it: num2occur) {
            if (occurMap[it.second]) {
                return false;
            }
            occurMap[it.second] = true;
        }
        
        return true;
    }
};

