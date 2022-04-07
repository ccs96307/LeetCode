class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {   
        // Init
        priority_queue<int> pq(stones.begin(), stones.end());
        int w1 = 0;
        int w2 = 0;
        
        // Destroy
        while (pq.size() > 1) {
            // w1
            w1 = pq.top();
            pq.pop();
            
            // w2
            w2 = pq.top();
            pq.pop();
            
            // New value
            if (w1 - w2 != 0) {
                pq.push(w1-w2);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};


