class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Init
        vector<bool> indegree(n, false);
        vector<int> results;

        // Find in-degree
        for (auto& edge: edges) {
            indegree[edge[1]] = true;
        }

        // Filter the vertices that have in-degree
        for (int i=0; i<n; ++i) {
            if (!indegree[i]) {
                results.emplace_back(i);
            }
        }

        return results;
    }
};

