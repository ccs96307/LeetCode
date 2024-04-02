class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Base case
        if (s.size() != t.size()) {
            return false;
        }
        
        // Init
        unordered_map<char, int> s2i;
        unordered_map<char, int> t2i;
        int si = 1;
        int ti = 1;

        // Compare
        for (int i=0; i<s.size(); ++i) {
            if (s2i[s[i]] != t2i[t[i]]) {
                return false;
            }

            if (s2i[s[i]] == 0) {
                s2i[s[i]] = si;
                t2i[t[i]] = ti;

                ++si;
                ++ti;
            }
        }

        return true;
    }
};

