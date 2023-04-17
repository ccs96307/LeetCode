class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Init
        int _max = 0;
        vector<bool> results(candies.size());

        // Get the maximum value of `candies`
        for (int i=0; i<candies.size(); ++i) {
            if (_max < candies[i]) {
                _max = candies[i];
            }
        }

        // Determine whether is larger than `_max`
        for (int i=0; i<candies.size(); ++i) {
            results[i] = (candies[i] >= _max);
        }

        return results;
    }
};

