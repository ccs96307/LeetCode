class Solution {
public:
    bool isValid(string s) {
        // Init
        vector<char> v;

        // Input char
        for (char w: s) {
            v.push_back(w);
            bool keep = true;
            while (keep && v.size() > 1) {
                keep = false;
                if (v[v.size()-1] == ')' && v[v.size()-2] == '(') {
                    v.pop_back();
                    v.pop_back();
                    keep = true;
                }
                else if (v[v.size()-1] == ']' && v[v.size()-2] == '[') {
                    v.pop_back();
                    v.pop_back();
                    keep = true;
                }
                else if (v[v.size()-1] == '}' && v[v.size()-2] == '{') {
                    v.pop_back();
                    v.pop_back();
                    keep = true;
                }
            }
        }

        // Check v is empty
        if (v.empty()) return true;
        return false;
    }
};