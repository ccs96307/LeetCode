class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Init
        int total = 0;
        vector<int> diff;
        
        // All people go to city A
        for (auto& cost: costs) {
            total += cost[0];
            diff.push_back(cost[1]-cost[0]);
        }
        
        // Sort
        sort(diff.begin(), diff.end());
        
        // Balance
        for (int i=0; i<costs.size()/2; ++i) {
            total += diff[i];
        }
        
        return total;
    }
};

