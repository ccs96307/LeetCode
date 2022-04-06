class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // Init
        int mod = pow(10, 9) + 7;
        long count = 0;
        
        // The times of number appear
        unordered_map<int, long> amounts;
        
        // Record
        for (int i=0; i<arr.size(); ++i) {
            ++amounts[arr[i]];
        }
        
        // Finding
        for (auto& a1: amounts) {
            for (auto& a2: amounts) {
                int i = a1.first;
                int j = a2.first;
                int k = target - i - j;
                
                // Hit
                if (amounts.count(k)) {
                    // Case: 1
                    if (i == j && j == k) {
                        count += amounts[i] * (amounts[i]-1) * (amounts[i]-2) / 6;
                    }
                    
                    // Case: 2
                    else if (i == j && j != k) {
                        count += amounts[i] * (amounts[i]-1) / 2 * amounts[k];
                    }
                    
                    // Case: 3
                    else if (i < j && j < k) {
                        count += amounts[i] * amounts[j] * amounts[k];
                    }
                }
            }
        }
        
        return count % mod;
    }
};

