class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Init
        vector<pair<int, int>> v;
        
        // Count
        for (int i=0; i<mat.size(); ++i) {
            int temp = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            v.push_back(pair{temp, i});
        }
        
        // Sort
        sort(v.begin(), v.end());
        
        // Pop
        while (v.size() > k) {
            v.pop_back();
        }
        
        // Return
        vector<int> results;
        for (int i=0; i<v.size(); ++i) {
            results.push_back(v[i].second);
        }
        
        return results;
    }
};

