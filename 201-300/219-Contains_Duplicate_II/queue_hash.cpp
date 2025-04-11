class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Base case
        if (k == 0) {
            return false;
        }
        
        // Init
        queue<int> currKNums;
        unordered_map<int, int> numAmount;
        
        // Find
        for (int& num: nums) {
            if (numAmount[num] > 0) {
                return true;
            }
            
            if (currKNums.size() >= k) {
                --numAmount[currKNums.front()];
                currKNums.pop();
            }
            
            // Update
            ++numAmount[num];
            currKNums.push(num);
        }
        
        return false;
    }
};
