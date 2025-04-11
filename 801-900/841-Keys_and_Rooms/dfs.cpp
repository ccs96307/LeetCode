class Solution {
public:
    void DFS(vector<vector<int>>& rooms, unordered_map<int, bool>& visited, int n) {
        for (auto& key: rooms[n]) {
            if (!visited[key]) {
                visited[key] = true;
                DFS(rooms, visited, key);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, bool> visited({{0, true}});
        DFS(rooms, visited, 0);

        return visited.size() == rooms.size();
    }
};

