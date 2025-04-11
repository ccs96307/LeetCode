class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Init
        vector<int> x;
        for (auto& point: points) {
            x.emplace_back(point[0]);
        }

        // Sort
        sort(x.begin(), x.end());

        // Find the widest distance
        int widest = 0;
        for (int i=1; i<x.size(); ++i) {
            widest = max(widest, x[i] - x[i-1]);
        }

        return widest;
    }
};

