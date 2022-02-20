class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort
        sort(intervals.begin(), intervals.end());

        // Init
        int ans = 1;
        int startpoint = intervals[0][0];
        int endpoint = intervals[0][1];
        
        // Comparison
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0] > startpoint && intervals[i][1] > endpoint) {
                ans += 1;
            }
            
            if (intervals[i][1] > endpoint) {
                startpoint = intervals[i][0];
                endpoint = intervals[i][1];
            }
        }
        
        return ans;
    }
};

