class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // Init
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        priority_queue<int> pq;
        
        // Maximize all odd elements
        for (int i=0; i<nums.size(); ++i) {            
            if (nums[i] % 2 == 1) {
                nums[i] *= 2;
            }
            
            // Push the element to queue
            pq.push(nums[i]);

            // Update "maxNum" and "minNum"
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
        
        // Declare the current minimum deviation
        int deviation = maxNum - minNum;
        
        // Decrease the maximum element ("pq.top()"), then we can minimize the deviation
        while (pq.top() % 2 == 0) {
            // Update deviation
            deviation = min(deviation, pq.top()-minNum);
            
            // Update queue
            int newTop = pq.top() / 2;
            pq.pop();
            pq.push(newTop);
            
            // Update minNum            
            minNum = min(minNum, newTop);
        }
        
        // The last check
        deviation = min(deviation, pq.top()-minNum);
        
        return deviation;
    }
};

