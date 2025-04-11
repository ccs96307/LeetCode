class Solution {
public:
    string sortVowels(string s) {
        // Init
        unordered_map<char, int> volwels({
            {'A', 1},
            {'E', 2},
            {'I', 3},
            {'O', 4},
            {'U', 5},
            {'a', 6},
            {'e', 7},
            {'i', 8},
            {'o', 9},
            {'u', 10},
        });

        // Count
        vector<pair<int, char>> volwels_pairs;
        vector<int> sPosition;
        for (int i=0; i<s.size(); ++i) {
            if (volwels.find(s[i]) != volwels.end()) {
                volwels_pairs.emplace_back(pair<int, char>({volwels[s[i]], s[i]}));
                sPosition.emplace_back(i);
            }
        }

        // Sort
        sort(volwels_pairs.begin(), volwels_pairs.end());

        // Reproduction
        for (int i=0; i<volwels_pairs.size(); ++i) {
            s[sPosition[i]] = volwels_pairs[i].second;
        }

        return s;
    }
};

