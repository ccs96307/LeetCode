class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Init
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        // Traversal
        for (int& price: prices) {
            if (price < min1) {
                min2 = min1;
                min1 = price;
            }
            else if (price < min2) {
                min2 = price;
            }
        }

        int remaining = money - min1 - min2;

        return remaining >= 0 ? remaining : money;
    }
};

