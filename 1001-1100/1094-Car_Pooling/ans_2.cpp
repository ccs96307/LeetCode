class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Init
        int current = 0;
        vector<pair<int, int>> changes;
        
        // Simplify
        for (auto trip: trips) {
            changes.push_back({trip[1], trip[0]});
            changes.push_back({trip[2], -trip[0]});
        }
        
        // Sort
        sort(changes.begin(), changes.end());

        // Start the trips!
        for (auto change: changes) {
            current += change.second;
            
            if (current > capacity) return false;
        }
        
        return true;
    }
};

