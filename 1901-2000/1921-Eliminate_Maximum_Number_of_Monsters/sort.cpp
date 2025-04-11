class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // Init
        int eliminate = 0;
        int turn = 1;
        std::vector<int> rounds;
        for (int i=0; i<dist.size(); ++i) {
            int round = (dist[i] + speed[i] - 1) / speed[i];
            rounds.emplace_back(round);
        }

        // Sort
        sort(rounds.begin(), rounds.end());

        // Eliminate monster
        for (int& round: rounds) {
            if (round < turn) {
                break;
            }

            ++eliminate;
            ++turn;
        }

        return eliminate;
    }
};

