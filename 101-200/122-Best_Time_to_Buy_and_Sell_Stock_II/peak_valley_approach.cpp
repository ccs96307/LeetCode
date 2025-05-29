class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int high = prices[0];
        int low = prices[0];
        int i = 0;

        while (i + 1 < prices.size()) {
            // Find the local lowest
            while (i + 1 < prices.size() && prices[i] >= prices[i+1]) {
                ++i;
            }

            low = prices[i];

            // Find the next local highest after the previous lowest
            while (i + 1 < prices.size() && prices[i] <= prices[i+1]) {
                ++i;
            }

            high = prices[i];

            maxProfit += high - low;
        }

        return maxProfit;
    }
};

