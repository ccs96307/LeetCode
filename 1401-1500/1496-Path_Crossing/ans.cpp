class Solution {
public:
    bool isPathCrossing(string path) {
        // Init
        std::pair<int, int> position = {0, 0};
        std::set<std::pair<int, int>> isVisited({position});
        std::unordered_map<char, pair<int, int>> dir2pos({
            {'N', {0, 1}},
            {'S', {0, -1}},
            {'E', {1, 0}},
            {'W', {-1, 0}},
        });

        for (char& dir: path) {
            position.first += dir2pos[dir].first;
            position.second += dir2pos[dir].second;

            if (isVisited.find(position) == isVisited.end()) {
                isVisited.insert(position);
            }
            else {
                return true;
            }
        }

        return false;
    }
};

