class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Init
        unordered_map<int, bool> visited({{0, true}});
        queue<int> q({0});
        for (int i=1; i<rooms.size(); ++i) {
            visited[i] = false;
        }

        // Visiting
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; ++i) {
                for (auto& vertex: rooms[q.front()]) {
                    if (visited[vertex]) {
                        continue;
                    }

                    visited[vertex] = true;
                    q.push(vertex);
                }
                q.pop();
            }
        }

        // If there is any room we haven't visited
        for (auto& it: visited) {
            if (it.second == false) {
                return false;
            }

            cout << it.first << " " << it.second << endl;
        }

        return true;
    }
};

