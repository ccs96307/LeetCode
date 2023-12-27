class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Init
        int total = 0;
        int temp_max = 0;

        // Base case
        if (colors.size() <= 1) {
            return 0;
        }

        for (int i=1; i<colors.size(); ++i) {
            if (colors[i] == colors[i-1]) {
                total += neededTime[i-1];
                temp_max = max(temp_max, neededTime[i-1]);
            }
            else if (temp_max != 0) {
                total += neededTime[i-1];
                temp_max = max(temp_max, neededTime[i-1]);
                total -= temp_max;
                temp_max = 0;
            }
        }

        if (temp_max != 0) {
            total += neededTime.back();
            temp_max = max(temp_max, neededTime.back());
            total -= temp_max;
        }

        return total;
    }
};

