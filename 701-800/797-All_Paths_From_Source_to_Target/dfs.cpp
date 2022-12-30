class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int vertex) {
        path.emplace_back(vertex);

        if (vertex == graph.size() - 1) {
            paths.emplace_back(path);
        } 
        else {
            for (int v: graph[vertex]) {
                DFS(graph, paths, path, v);
            }
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // Init
        vector<vector<int>> paths;
        vector<int> path;

        // Finding
        DFS(graph, paths, path, 0);

        return paths;
    }
};

