class Solution {
public:
    bool canSplit(vector<int>& nums, int m, int curr) {
        // Init
        int count = 1;
        int sum = 0;
        
        // Try to split
        for (int n: nums) {
            if (sum + n <= curr) {
                sum += n;
            }
            else {
                sum = n;
                ++count;
                
                if (count > m) return false;
            }            
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // Init
        int left = 0;
        int right = 0;
        
        // Determine the left and right boundary
        for (auto& n: nums) {
            right += n;
            left = max(left, n);
        }
        
        // Assign the worse case to initialize ans
        int ans = right;
        
        // Binary search
        while (left <= right) {
            int mid = left + (right-left) / 2;
            
            // If the mid number can split, try to find the more little sum
            if (canSplit(nums, m, mid)) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            
            // If mid number cannot split, try to find the larger sum
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};

