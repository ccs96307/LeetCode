class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // Init
        unordered_map<int, vector<int>> num2adj;
        for (int i=0; i<adjacentPairs.size(); ++i) {
            num2adj[adjacentPairs[i][0]].emplace_back(adjacentPairs[i][1]);
            num2adj[adjacentPairs[i][1]].emplace_back(adjacentPairs[i][0]);
        }

        // Find the start point
        int start;
        for (auto& it: num2adj) {
            if (it.second.size() == 1) {
                start = it.first;
                break;
            }
        }

        // Rebuild
        vector<int> results = {start, num2adj[start][0]};
        int prev = start;
        int curr = num2adj[start][0];

        while (num2adj[curr].size() > 1) {
            if (num2adj[curr][0] == prev) {
                results.emplace_back(num2adj[curr][1]);
            }
            else {
                results.emplace_back(num2adj[curr][0]);
            }

            prev = curr;
            curr = results.back();
        }

        return results; 
    }
};

