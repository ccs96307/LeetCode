class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Init
        int left = 0;
        int right = 0;
        int maxAmount = 0;
        unordered_map<int, int> mp;

        // Counting
        while (right < fruits.size()) {
            ++mp[fruits[right]];

            // If there are `THREE` kinds of fruits in the baskets
            while (mp.size() > 2) {
                --mp[fruits[left]];
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                ++left;
            }

            // Update the maximum amount
            maxAmount = max(maxAmount, right-left+1);
            ++right;
        }

        return maxAmount;
    }
};

