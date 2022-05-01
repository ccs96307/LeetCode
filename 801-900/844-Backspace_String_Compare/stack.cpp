class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Init
        stack<char> st_s;
        stack<char> st_t;
        
        // Complete
        for (char c: s) {
            if (c == '#') {
                if (!st_s.empty()) {
                    st_s.pop();
                }
            }
            else {
                st_s.push(c);
            }
        }
        
        for (char c: t) {
            if (c == '#') {
                if (!st_t.empty()) {
                    st_t.pop();
                }
            }
            else {
                st_t.push(c);
            }
        }
        
        return st_s == st_t;
    }
};

