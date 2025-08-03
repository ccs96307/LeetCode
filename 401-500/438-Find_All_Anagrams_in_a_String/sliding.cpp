class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Base case
        if (s.size() < p.size()) {
            return {};
        }

        // Init
        vector<int> results;
        
        vector<int> p_count(26, 0);
        for (char& c: p) {
            ++p_count[c-'a'];
        }

        vector<int> s_count(26, 0);
        for (int i=0; i<p.size(); ++i) {
            ++s_count[s[i]-'a'];
        }

        if (s_count == p_count) {
            results.emplace_back(0);
        }

        int left = 0;
        for (int i=p.size(); i<s.size(); ++i) {
            --s_count[s[left]-'a'];
            ++s_count[s[i]-'a'];

            ++left;

            if (s_count == p_count) {
                results.emplace_back(left);
            }        
        }

        return results;
    }
};

