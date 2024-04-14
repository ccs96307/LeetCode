class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Init
        int target = tickets[k];
        int total = target;

        // Count
        for (int i=0; i<k; ++i) {
            total += min(tickets[i], target);
        }

        for (int i=k+1; i<tickets.size(); ++i) {
            total += min(tickets[i], target-1);
        }

        return total;
    }
};


