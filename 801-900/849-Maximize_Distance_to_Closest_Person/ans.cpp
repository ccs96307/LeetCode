class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // Init
        int l = 0;
        int r = seats.size()-1;
        int maxDist = 0;
        int tempDist = 0;
        
        // Left side
        while (seats[l] == 0) {
            ++tempDist;
            ++l;
        }
        
        maxDist = max(maxDist, tempDist);
        tempDist = 0;
        
        // Right side
        while (seats[r] == 0) {
            ++tempDist;
            --r;
        }
        
        maxDist = max(maxDist, tempDist);
        tempDist = 0;
        
        for (int i=l; i<=r; ++i) {
            if (seats[i] == 0) ++tempDist;
            else tempDist = 0;
            
            if (tempDist % 2 == 0) {
                maxDist = max(maxDist, tempDist/2);
            }
            else {
                maxDist = max(maxDist, tempDist/2+1);
            }
        }
        
        return maxDist;
    }
};

