class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Init
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        // Binary search
        while (l <= r) {
            // Settings
            int mid = l + ((r - l) / 2);
            int _h = 0;
            bool tooMuchTime = false;
            
            // Check the cost time
            for (int pile: piles) {
                _h += pile / mid;
                if (pile % mid != 0) ++_h;
                if (_h > h) {
                    tooMuchTime = true;
                    break;
                }
            }
            
            // If use too much time, left move to middle + 1; else, right move to middle -1 ;
            if (tooMuchTime) l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
};

