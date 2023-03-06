class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 1;

        for (int i=0; i<arr.size(); ++i) {
            while (missing != arr[i]) {
                --k;
                if (k == 0) {
                    return missing;
                }
                ++missing;
            }
            ++missing;
        }

        return missing + k - 1;
    }
};

