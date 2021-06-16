class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        int profit=0;
        int buy=10001;
                
        for (int i=0; i<prices.size(); ++i) {
            if (prices[i] < buy) buy = prices[i];
            if (profit < prices[i]-buy) profit = prices[i] - buy;
        }
        
        return profit;
    }
};

