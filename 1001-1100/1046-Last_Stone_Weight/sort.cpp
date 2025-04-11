class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {   
        // Sort
        sort(stones.begin(), stones.end());
        
        while (stones.size() > 1) {
            stones[stones.size()-2] = stones.back() - stones[stones.size()-2];
            stones.pop_back();
            if (stones.back() == 0) stones.pop_back();
            
            // Sort
            for (int i=stones.size()-1; i>0; --i) {
                if (stones[i] < stones[i-1]) {
                    swap(stones[i], stones[i-1]);
                }
                else break;
            }
        }
        
        return stones.empty() ? 0 : stones.front();
    }
};


