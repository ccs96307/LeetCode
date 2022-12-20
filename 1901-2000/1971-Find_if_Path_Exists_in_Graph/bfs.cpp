class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Base case
        if (source == destination) {
            return true;
        }
        
        // Init
        queue<int> q({source});
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> isVisited({{source, true}});
        for (auto& edge: edges) {
            mp[edge[0]].emplace_back(edge[1]);
            mp[edge[1]].emplace_back(edge[0]);
        }

        // Find the path
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; ++i) {
                int vertex = q.front();
                isVisited[vertex] = true;
                q.pop();

                for (int& v: mp[vertex]) {
                    if (isVisited[v]) {
                        continue;
                    }

                    if (v == destination) {
                        return true;
                    }

                    q.push(v);
                }
            }
        }

        return false;
    }
};

