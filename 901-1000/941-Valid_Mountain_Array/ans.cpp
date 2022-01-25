class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Base case
        if (arr.size() <= 2) return false;
        
        // Init
        int i = 1;
        bool up = false;
        bool down = false;
        
        // Up
        while (i < arr.size()) {
            if (arr[i] == arr[i-1]) return false;
            else if (arr[i] > arr[i-1]) up = true;
            else if (arr[i] < arr[i-1]) break;
            ++i;
        }
        
        // If never increasing, it is not a valid mountain array!
        if (!up) return false;
        
        // Down
        while (i < arr.size()) {
            if (arr[i] == arr[i-1]) return false;
            else if (arr[i] < arr[i-1]) down = true;
            else if (arr[i] > arr[i-1]) return false;
            ++i;
        }
        
        // If never decreasing, it is not a valid mountain array either.
        if (!down) return false;
        
        // Valid
        return true;
    }
};

