class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Init
        int stoneSum = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());

        // Remove stones
        while (pq.top() != 0 && k > 0) {
            int removeStone = floor(pq.top() / 2);
            int remainStone = pq.top() - removeStone;
            pq.pop();
            pq.push(remainStone);
            stoneSum -= removeStone;
            --k;
        }

        return stoneSum;
    }
};

