class Solution {
public:
    int search(vector<int>& nums, int target) {        
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + ((right - left) >> 1);

            if (nums[mid] == target) {
                return mid;
            }

            // If the left side is ordered
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            // If the right side is ordered
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
