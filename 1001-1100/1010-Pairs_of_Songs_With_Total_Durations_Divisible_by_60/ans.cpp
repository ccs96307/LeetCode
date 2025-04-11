class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // Init
        int count = 0;
        vector<int> losses(60, 0);
        
        // Iteration
        for (int i=0; i<time.size(); ++i) {
            int loss = time[i] % 60;
            int lack = (60 - loss) % 60;
            
            count += losses[loss];
            ++losses[lack];
        }
        
        return count;
    }
};

