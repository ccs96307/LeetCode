class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // Init
        int numbers = 0;
        int prev = 0;
        int curr = 0;

        // Count
        for (int i=0; i<bank.size(); ++i) {
            for (char& c: bank[i]) {
                if (c == '1') {
                    ++curr;
                }
            }

            // If this layer is null, skip it
            if (curr == 0) {
                continue;
            }

            numbers += prev * curr;
            prev = curr;
            curr = 0;
        }

        return numbers;
    }
};

