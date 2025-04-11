class Solution {
public:    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // Offset
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        // Init
        int steps = 0;
        int _x = entrance[0];
        int _y = entrance[1];
        
        int width = maze.size();
        int height = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({_x, _y});
        
        vector<vector<bool>> isVisited(width, vector<bool>(height, 0));
        isVisited[_x][_y] = 1;
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            ++steps;
            
            while (size) {
                --size;
                
                _x = q.front().first;
                _y = q.front().second;
                q.pop();
                
                for (int i=0; i<4; ++i) {
                    int new_x = _x + dx[i];
                    int new_y = _y + dy[i];
                    
                    // Out of the boundary
                    if (new_x < 0 || new_y < 0 || new_x >= width || new_y >= height) {
                        continue;
                    }
                    
                    // Wall or is visited
                    if (maze[new_x][new_y] == '+' || isVisited[new_x][new_y]) {
                        continue;
                    }
                    
                    // Reach the exit
                    if (new_x == 0 || new_y == 0 || new_x == width-1 || new_y == height-1) {
                        return steps;
                    }
                    
                    isVisited[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        
        return -1;
    }
};

