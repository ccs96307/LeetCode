class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // Init
        int bag = 0;
        priority_queue<int, vector<int>, greater<int>> losses;

        // Record the losses
        for (int i=0; i<rocks.size(); ++i) {
            int loss = capacity[i] - rocks[i];
            if (loss != 0) {
                losses.push(loss);
            }
            else {
                ++bag;
            }
        }

        // Fill the bags
        while (!losses.empty()) {
            additionalRocks -= losses.top();
            losses.pop();
            ++bag;

            if (additionalRocks < 0) {
                --bag;
                break;
            }
        }
        
        return bag;
    }
};

