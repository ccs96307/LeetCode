class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // Init
        int odd = 0;
        int even = 0;

        // Move
        for (int i=0; i<position.size(); ++i) {
            if (position[i] % 2 == 0) {
                ++even;
            }
            else {
                ++odd;
            }
        }
        
        return min(odd, even);
    }
};

