class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Base case
        if (points.size() <= 1) return points.size();
        
        // Sort
        sort(points.begin(), points.end());
        
        // Init
        int arrows = 1;
        int hit_range = points[0][1];
        
        for (int i=1; i<points.size(); ++i) {
            // New point out of range, we need more arrow
            if (points[i][0] > hit_range) {
                ++arrows;
                hit_range = points[i][1];
            }
            
            // If we want to hit it by an arrow, we need update the new hit range
            if (points[i][1] < hit_range) hit_range = points[i][1];
        }
        
        return arrows;
    }
};

