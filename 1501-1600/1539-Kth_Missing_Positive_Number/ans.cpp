class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Init
        int missing = 1;

        // Comparing with the `arr` one by one
        for (int i=0; i<arr.size(); ++i) {
            // If `missing` not in `arr`, that means we can count down `k` value
            while (missing != arr[i]) {
                --k;
                if (k == 0) {
                    return missing;
                }
                ++missing;
            }
            ++missing;
        }

        // If `arr` is over and we do not find the answer, we can calculate the results directly
        return missing + k - 1;
    }
};

