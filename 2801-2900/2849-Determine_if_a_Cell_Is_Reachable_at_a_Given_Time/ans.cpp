class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Base case
        if (sx == fx && sy == fy && t == 1) {
            return false;
        }
        
        // Init
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);

        // Check
        t -= max(dx, dy);

        return t >= 0;
    }
};

