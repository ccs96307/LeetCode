class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Base case
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> results = {intervals[0]};
        
        for (int i=1; i<intervals.size(); ++i) {
            vector<int> &last = results.back();

            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            }
            else {
                results.emplace_back(intervals[i]);
            }
        }

        return results;
    }
};

