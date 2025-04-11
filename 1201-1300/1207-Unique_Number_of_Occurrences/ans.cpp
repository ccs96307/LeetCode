class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Init
        unordered_map<int, int> count;
        unordered_set<int> occurences;

        // Count
        for (int& n: arr) {
            ++count[n];
        }

        // Check unique proterty
        for (auto& it: count) {
            if (occurences.find(it.second) == occurences.end()) {
                occurences.insert(it.second);
            }
            else {
                return false;
            }
        }

        return true;
    }
};
