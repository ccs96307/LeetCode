class Solution {
public:
    void fitAndPop(vector<char>& v) {
        if (v.size() < 2) return;
        
        if (v[v.size()-2] == '(' && v[v.size()-1] == ')') {
            v.pop_back();
            v.pop_back();
            fitAndPop(v);
        }
        else if (v[v.size()-2] == '{' && v[v.size()-1] == '}') {
            v.pop_back();
            v.pop_back();
            fitAndPop(v);
        }
        else if (v[v.size()-2] == '[' && v[v.size()-1] == ']') {
            v.pop_back();
            v.pop_back();
            fitAndPop(v);
        }
    }
    
    bool isValid(string s) {
        // Init
        int i = 1;
        vector<char> v({s[0]});
        
        // Matching
        for (int i=1; i<s.size(); ++i) {
            v.push_back(s[i]);
            fitAndPop(v);
        }
        
        return (v.empty());
    }
};

