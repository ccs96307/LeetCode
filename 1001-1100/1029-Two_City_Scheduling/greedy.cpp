class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Init
        int a = 0;
        int b = 0;
        int total = 0;
        vector<int> aDiff;
        vector<int> bDiff;
        
        // Compute distances of city a and b; then greedy to determine where they go
        for (auto& cost: costs) {
            if (cost[0] < cost[1]) {
                ++a;
                total += cost[0];
                aDiff.push_back(cost[1]-cost[0]);
            }
            else {
                ++b;
                total += cost[1];
                bDiff.push_back(cost[0]-cost[1]);
            }
        }
        
        // Sort
        sort(aDiff.begin(), aDiff.end());
        sort(bDiff.begin(), bDiff.end());
                
        // Balance
        if (a < b) {
            int diff = (b - a) / 2;
            for (int i=0; i<diff; ++i) {
                total += bDiff[i];
            }
        }
        else if (b < a) {
            int diff = (a - b) / 2;
            for (int i=0; i<diff; ++i) {
                total += aDiff[i];
            }
        }
        
        return total;
    }
};

