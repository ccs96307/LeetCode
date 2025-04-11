class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // Init
        int eliminate = 0;
        int turn = 1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> rounds;
        for (int i=0; i<dist.size(); ++i) {
            int round = dist[i] % speed[i] ? dist[i] / speed[i] + 1 : dist[i] / speed[i];
            rounds.push(round);
        }

        // Eliminate
        while (!rounds.empty()) {
            if (rounds.top() < turn) {
                break;
            }

            ++eliminate;
            ++turn;
            rounds.pop();
        }

        return eliminate;
    }
};

