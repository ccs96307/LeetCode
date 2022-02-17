class Solution {
public:
    void DFS(vector<vector<int>>& results, vector<int>& result, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            results.push_back(result);
            return;
        }
        
        if (target < 0) return;
                
        for (int i=start; i<candidates.size(); ++i) {
            result.push_back(candidates[i]);
            DFS(results, result, candidates, target-candidates[i], i);
            result.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Init
        vector<int> result;
        vector<vector<int>> results;
        
        DFS(results, result, candidates, target, 0);
        
        return results;
    }
};

