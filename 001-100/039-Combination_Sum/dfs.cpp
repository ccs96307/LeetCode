class Solution {
public:
    void DFS(vector<vector<int>>& results, vector<int>& result, vector<int>& candidates, int target) {
        if (target == 0) {
            results.push_back(result);
            return;
        }
        
        if (target < 0) return;
        
        for (int n: candidates) {
            if (n >= result.back() && n <= target) {
                result.push_back(n);
                DFS(results, result, candidates, target-n);
                result.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Init
        int i = 0;
        vector<vector<int>> results;
        
        for (int n: candidates) {
            if (n <= target) {
                vector<int> result({n});
                DFS(results, result, candidates, target-n);
            }
        }
        
        return results;
    }
};

