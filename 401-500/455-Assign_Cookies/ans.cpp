class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Init
        int _max = 0;
        
        // Sort
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        // Assign
        int si = s.size() - 1;
        int gi = g.size() - 1;

        while (si >= 0 && gi >= 0) {
            if (s[si] >= g[gi]) {
                ++_max;
                --si;
                --gi;
            }
            else {
                --gi;
            }
        }

        return _max;
    }
};

