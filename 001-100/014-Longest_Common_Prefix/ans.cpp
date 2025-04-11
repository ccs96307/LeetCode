class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Preventation
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        // Init
        string ans = "";
        int min_len = 200;
        
        for (string str: strs) {
            if (str.size() < min_len) {
                min_len = str.size();
            }
        }
                
        // Comparison
        for (int i=0; i<min_len; i++) {
            for (int si=0; si<strs.size()-1; si++) {
                if (strs[si][i] != strs[si+1][i]) {
                    return ans;
                }                
            }
            
            ans += strs[0][i];
        }
        
        return ans;
    }
};
