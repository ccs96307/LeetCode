class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // Init
        int coins = 0;
        int left = 0;
        int right = piles.size() - 1;
        
        // Sort
        sort(piles.begin(), piles.end());

        // Count
        while (left < right - 1) {
            coins += piles[right-1];
            ++left;
            right -= 2;
        }

        return coins;
    }
};

