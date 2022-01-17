class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Init
        int i = 0;
        unordered_map<string, char> s2p;
        istringstream tokens(s);
        string token;
        
        // token is a word split by space ' '
        while (getline(tokens, token, ' ')) {
            // If token exist in s2p, check the corresponding pattern[i], if it's different, return false
            if (s2p.find(token) != s2p.end()) {
                if (s2p[token] != pattern[i]) return false; 
            }
            
            // If the new token mapping to a exist value, it means the pattern is not match, return false
            else {
                for (auto item: s2p) {
                    if (item.second == pattern[i]) return false;
                }
                s2p[token] = pattern[i];
            }
            ++i;
        }
        
        // If the i less than pattern size, it means the pattern not match
        if (i != pattern.size()) return false;
        
        return true;        
    }
};

