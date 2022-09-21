class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Init
        vector<int> results;
        int sum = 0;
        for (auto& n: nums) {
            if (n % 2 == 0) {
                sum += n;
            }
        }
                
        // Add
        for (int i=0; i<queries.size(); ++i) {
            int _add = queries[i][0];
            int _old = nums[queries[i][1]];
            
            nums[queries[i][1]] += queries[i][0];
            int _new = nums[queries[i][1]];
                        
            if (_old % 2 == 0) {
                if (_add % 2 == 0) {
                    sum += _add;
                }
                else {
                    sum -= _old;
                }
            }
            else {
                if (_add % 2 != 0) {
                    sum += _new;
                }
            }
                        
            results.push_back(sum);
        }
        
        return results;
    }
};

