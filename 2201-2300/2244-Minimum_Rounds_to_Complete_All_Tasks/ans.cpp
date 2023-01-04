class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Init
        int rounds = 0;
        unordered_map<int, int> mp;
        for (int& task: tasks) {
            ++mp[task];
        }

        // Count `rounds`
        for (auto& it: mp) {
            if (it.second == 1) {
                return -1;
            }

            rounds += it.second % 3 ? it.second / 3 + 1 : it.second / 3;
        }

        return rounds;
    }
};
``
