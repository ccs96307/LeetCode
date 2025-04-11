class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Init
        priority_queue<int> pq;
        int stoneSum = 0;

        // Accumulate
        for (int& pile: piles) {
            pq.push(pile);
            stoneSum += pile;
        }

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

