class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Init
        unordered_map<char, int> p2idx;
        unordered_map<string, int> s2idx;
        vector<int> pIndex;
        vector<int> sIndex;

        // Count `pattern`
        int idx = 0;
        for (char& p: pattern) {
            if (!p2idx.count(p)) {
                p2idx[p] = idx;
                ++idx;
            }

            pIndex.emplace_back(p2idx[p]);
        }

        // Count `s`
        int i = 0;
        string temp;
        idx = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                if (!s2idx.count(temp)) {
                    s2idx[temp] = idx;
                    ++idx;
                }

                sIndex.emplace_back(s2idx[temp]);
                temp.clear();
            }
            else {
                temp.push_back(s[i]);
            }

            ++i;
        }

        if (!s2idx.count(temp)) {
            s2idx[temp] = idx;
            ++idx;
        }

        sIndex.emplace_back(s2idx[temp]);
        temp.clear();

        return pIndex == sIndex;
    }
};

