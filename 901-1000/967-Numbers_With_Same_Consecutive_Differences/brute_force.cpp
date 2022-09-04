class Solution {
public:
    void bfs(int n, int k, int limitVal, int currVal, vector<int>& v, vector<int>& results) { 
        if (v.size() == n) {
            int result = 0;
            
            for (int i=0; i<n; ++i) {
                result += v[v.size()-i-1]*pow(10, i);
            }
            
            if (result >= limitVal) {
                results.push_back(result);
            }
            
            return;
        }
        
        if (currVal + k < 10) {
            vector<int> _v(v);
            _v.push_back(currVal+k);
            bfs(n, k, limitVal, currVal+k, _v, results);
        }
        
        if (currVal - k >= 0) {
            vector<int> _v(v);
            _v.push_back(currVal-k);
            bfs(n, k, limitVal, currVal-k, _v, results);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        // Init
        int limitVal = pow(10, n-1);
        vector<int> results;
        
        // Start BFS
        for (int currVal=0; currVal<10; ++currVal) {
            vector<int> v({currVal});
            bfs(n, k, limitVal, currVal, v, results);
        }
        
        // Drop duplicated
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        
        // Return
        return results;
    }
};

