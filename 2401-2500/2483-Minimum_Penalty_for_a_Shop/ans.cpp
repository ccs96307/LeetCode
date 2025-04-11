class Solution {
public:
    int bestClosingTime(string customers) {
        // Init
        int minPenalty = INT_MAX;
        int closeIdx = customers.size();
        int penalty = 0;

        // Close at the last hour
        for (char& customer: customers) {
            if (customer == 'N') {
                ++penalty;
            }
        }

        minPenalty = min(minPenalty, penalty);

        for (int i=customers.size()-1; i>=0; --i) {            
            if (customers[i] == 'Y') {
                ++penalty;
            }
            else {
                --penalty;

                if (penalty <= minPenalty) {
                    minPenalty = penalty;
                    closeIdx = i;
                }
            }
        }

        return closeIdx;
    }
};


