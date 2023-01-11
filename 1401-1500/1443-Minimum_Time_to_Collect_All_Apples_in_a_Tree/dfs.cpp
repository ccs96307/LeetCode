class Solution {
public:
    int DFS(int vertex, unordered_map<int, vector<int>>& trees, vector<bool>& hasApple, unordered_map<int, bool>& visited) {
        // Init
        int n = 0;

        // We visit the current node, update the `visited`
        visited[vertex] = true;

        // DFS
        for (auto& v: trees[vertex]) {
            if (visited[v]) {
                continue;
            }
            n += DFS(v, trees, hasApple, visited);
        }

        // If there are no any apple and the current node have no apple eigther
        return n == 0 && !hasApple[vertex] ? 0 : n + 2;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Init
        unordered_map<int, vector<int>> trees;
        unordered_map<int, bool> visited;
        for (auto& edge: edges) {
            trees[edge[0]].emplace_back(edge[1]);
            trees[edge[1]].emplace_back(edge[0]);
        }

        int num = DFS(0, trees, hasApple, visited);

        return num ? num - 2 : 0;
    }
};

