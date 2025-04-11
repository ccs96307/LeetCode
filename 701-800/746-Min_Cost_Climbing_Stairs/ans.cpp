class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Init
        vector<int> costs(cost.begin(), cost.begin()+1);

        // Compute
        for (int i=2; i<cost.size(); ++i) {
            cost[i] += min(cost[i-1] , cost[i-2]);
        }

        return min(cost.back(), cost[cost.size()-2]);
    }
};

