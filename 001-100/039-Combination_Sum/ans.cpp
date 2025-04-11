class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort
        sort(candidates.begin(), candidates.end());
        
        // Init
        vector<vector<int>> results;
        vector<int> result = {candidates[0]};
        vector<int> index = {0};
        int p = 0;
        
        // Find
        while (true) {
            // Add a new value in result
            if (std::accumulate(result.begin(), result.end(), 0) < target) {
                index.push_back(index[p]);
                result.push_back(0);
                ++p;                
            }
            
            // Remove the last value and change the size()-1 index value
            else if (std::accumulate(result.begin(), result.end(), 0) > target) {
                --p;
                
                if (p == -1) break;
                
                index.pop_back();
                result.pop_back();
                
                // Change
                while (index[p] >= candidates.size()-1) {
                    if (index.size() == 1) {
                        return results;
                    }
                    else {
                        --p;
                        if (p == -1) return results;
                        
                        index.pop_back();
                        result.pop_back();
                    }
                }
                
                ++index[p];
            }
            
            // Equal to target
            else {
                results.push_back(result);
                --p;
                
                if (p == -1) break;
                
                index.pop_back();
                result.pop_back();
                
                // Change
                while (index[p] >= candidates.size()-1) {
                    if (index.size() == 1) {
                        return results;
                    }
                    else {
                        --p;
                        if (p == -1) return results;
                        
                        index.pop_back();
                        result.pop_back();
                    }
                }
                
                ++index[p];
            }
            
            // Change
            result[p] = candidates[index[p]];
            
            // Print
            // for (auto n: result) {
            //     printf("%d ", n);
            // }
            // printf("===============\n");
        }
        
        // Return
        return results;
    }
};

