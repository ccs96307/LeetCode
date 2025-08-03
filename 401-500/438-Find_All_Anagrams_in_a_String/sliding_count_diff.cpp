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

        // Optimization
        int diff = 0;
        for (int i=0; i<26; ++i) {
            if (s_count[i] != p_count[i]) {
                ++diff;
            }
        }

        if (diff == 0) {
            results.emplace_back(0);
        }

        int left = 0;
        for (int i=p.size(); i<s.size(); ++i) {
            int out_idx = s[left] - 'a';
            int in_idx = s[i] - 'a';

            // Out
            if (s_count[out_idx] == p_count[out_idx]) {
                ++diff;
            }
            --s_count[out_idx];
            if (s_count[out_idx] == p_count[out_idx]) {
                --diff;
            }

            // In
            if (s_count[in_idx] == p_count[in_idx]) {
                ++diff;
            }
            ++s_count[in_idx];
            if (s_count[in_idx] == p_count[in_idx]) {
                --diff;
            }

            ++left;

            if (diff == 0) {
                results.emplace_back(left);
            }        
        }

        return results;
    }
};
