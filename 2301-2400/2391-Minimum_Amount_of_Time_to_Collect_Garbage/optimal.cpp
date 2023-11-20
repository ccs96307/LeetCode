class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Init
        int total = 0;
        unordered_map<char, int> c2n;

        // Count the total times
        for (int i=garbage.size()-1; i>0; --i) {
            for (int j=0; j<garbage[i].size(); ++j) {
                ++c2n[garbage[i][j]];
            }

            if (c2n['G'] > 0) {
                total += travel[i-1];
            }

            if (c2n['P'] > 0) {
                total += travel[i-1];
            }

            if (c2n['M'] > 0) {
                total += travel[i-1];
            }
        }

        // At house 0
        for (char& c: garbage.front()) {
            ++c2n[c];
        }

        return total + c2n['G'] + c2n['P'] + c2n['M'];
    }
};

