class Solution {
public:
    void DFS(vector<vector<int>>& results, vector<int>& candidates, vector<int>& v, int target, int i) {
        // Base case
        if (target == 0) {
            results.emplace_back(v);
            return;
        }
        else if (target < 0 || i >= candidates.size()) {
            return; 
        }

        // DFS
        for (int _i=i; _i<candidates.size(); ++_i) {
            // We do not want to select the same element
            if (_i > i && candidates[_i] == candidates[_i-1]) {
                continue;
            }

            v.emplace_back(candidates[_i]);
            DFS(results, candidates, v, target-candidates[_i], _i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Init
        vector<vector<int>> results;
        vector<int> v;

        // Sort
        sort(candidates.begin(), candidates.end());

        // DFS
        DFS(results, candidates, v, target, 0);

        return results;
    }
};

