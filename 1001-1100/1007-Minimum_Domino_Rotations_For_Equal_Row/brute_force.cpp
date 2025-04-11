class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Init
        int minTried = INT_MAX;
        unordered_map<int, int> used;
        
        // Find the mini-steps method
        for (int prob: tops) {
            int temp = 0;
            bool isBreak = false;
            
            if (used.count(prob)) continue;
            else used[prob] = 1;
            
            for (int i=0; i<tops.size(); ++i) {
                if (tops[i] != prob) {
                    // If bottom can exchange, increase the `temp` variable
                    if (bottoms[i] == prob) {
                        ++temp;
                    }
                    
                    // If top and bottom is not equal to prob[i], break out the matching
                    else {
                        isBreak = true;
                        break;
                    }
                }
            }
            
            if (!isBreak) {
                // Maybe we rotate bottoms is faster than tops
                temp = min(temp, int(tops.size()-temp));
                
                // Minimum
                minTried = min(minTried, temp);
            }
        }
        
        // Use Bottom to calculation
        used.clear();
        
        // Find the mini-steps method
        for (int prob: bottoms) {
            int temp = 0;
            bool isBreak = false;
            
            if (used.count(prob)) continue;
            else used[prob] = 1;
            
            for (int i=0; i<bottoms.size(); ++i) {
                if (bottoms[i] != prob) {
                    // If bottom can exchange, increase the `temp` variable
                    if (tops[i] == prob) {
                        ++temp;
                    }
                    
                    // If top and bottom is not equal to prob[i], break out the matching
                    else {
                        isBreak = true;
                        break;
                    }
                }
            }
            
            if (!isBreak) {
                // Maybe we rotate bottoms is faster than tops
                temp = min(temp, int(tops.size()-temp));
                
                // Minimum
                minTried = min(minTried, temp);
            }
        }
        
        // If the minTried is still `INT_MAX`, that means it cannot be done
        return minTried == INT_MAX ? -1 : minTried;
    }
};

