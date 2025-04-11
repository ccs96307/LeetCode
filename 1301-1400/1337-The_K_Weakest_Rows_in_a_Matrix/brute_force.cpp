class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Init
        map<int, vector<int>> mp;
        
        // Count
        for (int i=0; i<mat.size(); ++i) {
            int temp = 0;
            for (auto& n: mat[i]) {
                temp += n;
            }
            
            if (mp.count(temp)) {
                mp[temp].push_back(i);
            }
            else {
                mp[temp] = {i};
            }
        }
        
        // Return
        vector<int> results;
        
        while (k > 0) {
            for (auto& it: mp) {
                for (auto& n: it.second) {
                    results.push_back(n);
                    --k;
                    
                    if (k == 0) return results;
                }
            }
        }
        
        return results;
    }
};

