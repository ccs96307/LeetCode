class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // sort
        std::sort(prices.begin(), prices.end());

        int remaining = money - prices[0] - prices[1];

        return remaining >= 0 ? remaining : money;
    }
};

