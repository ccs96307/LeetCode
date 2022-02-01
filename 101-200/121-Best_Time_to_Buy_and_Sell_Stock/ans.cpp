class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Init
        int profit = 0;
        int buy = INT_MAX;
            
        // Determine
        for (int price: prices) {
            buy = min(buy, price);
            profit = max(profit, price-buy);
        }
                    
        return profit;
    }
};

