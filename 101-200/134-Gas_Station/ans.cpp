class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Init
        int total_sum = 0;
        int sum = 0;
        int startpoint = 0;
        
        for (int i=0; i<gas.size(); ++i) {
            total_sum = total_sum + gas[i] - cost[i];
            sum = sum + gas[i] - cost[i];
            
            if (sum < 0) {
                startpoint = i+1;
                sum = 0;
            }
        }
        
        return total_sum >= 0 ? startpoint : -1;
    }
};
