class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // Init
        int index = 0;
        int minDiff = INT_MAX;
        long left = 0;
        long right = (long)accumulate(nums.begin(), nums.end(), 0L);
        int leftNum = 0;
        int rightNum = nums.size();
        
        // Loop
        for (int i=0; i<nums.size(); ++i) {
            left += nums[i];
            right -= nums[i];
            
            // Calculate the difference between the average of the left and right part
            ++leftNum;
            rightNum = max(1, rightNum-1);
            int avgDiff = abs((int)(left/leftNum) - (int)(right/rightNum));
            
            // Update the minimum average difference
            if (minDiff > avgDiff) {
                minDiff = avgDiff;
                index = i;
            }
        }
                                   
        return index;
    }
};

