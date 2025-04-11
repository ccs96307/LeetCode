class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Init
        int boats = 0;
        int l = 0;
        int r = people.size() - 1;
        
        // Sort
        sort(people.begin(), people.end());
        
        // Two pointer
        while (l <= r) {            
            if (people[l] + people[r] <= limit) {
                ++l;
                --r;
            }
            else {
                --r;
            }
            
            // Increase number of boats
            ++boats;
        }
        
        return boats;
    }
};

