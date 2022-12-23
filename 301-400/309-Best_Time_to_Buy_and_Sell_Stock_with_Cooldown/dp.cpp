class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Base case
        if (prices.size() == 1) {
            return 0;
        }

        // Init
        vector<int> sell({0});
        vector<int> buy({-1*prices[0]});
        vector<int> cooldown({0});

        // Filling
        for (int i=1; i<prices.size(); ++i) {
            sell.emplace_back(max(sell.back(), buy.back() + prices[i]));
            buy.emplace_back(max(buy.back(), cooldown.back() - prices[i]));
            cooldown.emplace_back(max(cooldown.back(), sell[i-1]));
        }

        return sell.back();
    }
};

