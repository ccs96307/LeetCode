class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int best_i = values[0];

        for (int j=1; j<values.size(); ++j) {
            ans = max(ans, best_i + (values[j] - j));
            best_i = max(best_i, values[j] + j);
        }

        return ans;
    }
};

