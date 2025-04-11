class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Init
        int highestPlayer = 0;
        unordered_map<int, int> lossTimes;
        vector<vector<int>> results(2);
        
        // Records match results
        for (int i=0; i<matches.size(); ++i) {
            lossTimes[matches[i][0]] += 0;
            lossTimes[matches[i][1]] += 1;
            highestPlayer = max(max(matches[i][0], matches[i][1]), highestPlayer);
        }
        
        // Save to `results`
        for (int i=1; i<=highestPlayer; ++i) {
            if (!lossTimes.count(i)) {
                continue;
            }
            if (lossTimes[i] == 0) {
                results[0].push_back(i);
            }
            else if (lossTimes[i] == 1) {
                results[1].push_back(i);
            }
        }
        
        return results;
    }
};

