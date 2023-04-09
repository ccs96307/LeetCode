class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        // `adj` save edges of directed graph
        vector<vector<int>> adj(n);
        
        // `indegree` save indegree of nodes
        vector<int> indegree(n, 0);

        // Traversal, then save the connected edge and indegree
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            ++indegree[edge[1]];
        }

        // Initialize a `dp` array to store the color label (a to z are 26 letters)
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> q;
        for (int i=0; i<n; ++i) {
            if (indegree[i] == 0) {
                q.push_back(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        // If `q` is not empty, pick up `u` in top of `q` and update the `dp` with its connect node `u` 
        int ans = 0;
        int cnt = 0;
        while (!q.empty()) {
            // Get the top of `q`
            int u = q.back();
            q.pop_back();

            // Add 1 to cnt
            ++cnt;

            for (int v: adj[u]) {
                // Update `dp`
                for (int i=0; i<26; ++i) {
                    int val = (i == colors[v]-'a') ? dp[u][i]+1 : dp[u][i];
                    dp[v][i] = max(dp[v][i], val);
                }

                // If in-degree is equal to 0, add it to `q` and will be started a new counting
                if (--indegree[v] == 0) {
                    q.push_back(v);
                }
            }

            // Set `ans` to the current maximum value of `dp`
            ans = max(ans, *max_element(dp[u].begin(), dp[u].end()));
        }

        // If not loop, return `ans`
        return cnt == n ? ans : -1;
    }
};

