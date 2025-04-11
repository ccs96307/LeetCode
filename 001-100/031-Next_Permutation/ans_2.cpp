class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Init
        bool decreasing = true;
        
        // Init        
        for (int i=nums.size()-2; i>=0; --i) {
            if (nums[i] < nums[i+1]) {
                decreasing = false;
                int id = 0;
                
                for (int j=nums.size()-1; j>i; --j) {
                    if (nums[j] > nums[i]) {
                        id = j;
                        break;
                    }
                }
                
                // Swap
                cout << i << " " << id << endl;
                swap(nums[i], nums[id]);
                
                // Sort
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        
        // If decreasing
        if (decreasing) {
            sort(nums.begin(), nums.end());
        }        
    }
};

