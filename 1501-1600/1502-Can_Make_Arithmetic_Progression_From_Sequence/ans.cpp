class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Sort
        sort(arr.begin(), arr.end());

        // Init
        int diff = arr[1] - arr[0];

        // Check
        for (int i=2; i<arr.size(); ++i) {
            if (arr[i] - arr[i-1] != diff) {
                return false;
            }
        }
        
        return true;
    }
};

