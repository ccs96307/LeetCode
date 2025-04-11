class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Init
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        
        // For-loop
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                int left = j+1;
                int right = nums.size()-1;
                int temp_target = target - nums[i] - nums[j];
                
                while (left < right) {
                    int lr_sum = nums[left] + nums[right];
                    
                    if (lr_sum == temp_target) {
                        vector<int> result = {nums[i], nums[j], nums[left], nums[right]};
                        
                        if (find(results.begin(), results.end(), result) == results.end()) {
                            results.push_back(result);
                        }
                        left++;
                        right--;
                    }   
                    else if (lr_sum < temp_target) {
                        left++;
                    }
                    else if (lr_sum > temp_target) {
                        right--;
                    }
                }
            }
        }
        
        return results;
    }
};
