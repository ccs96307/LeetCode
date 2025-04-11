class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Init
        int count = 0;
        
        // Left to right
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') ++count;
            else if (s[i] == ')') {
                if (count) --count;
                else s[i] = '*';
            }
        }
        
        // Right to left
        count = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == ')') ++ count;
            else if (s[i] == '(') {
                if (count) --count;
                else s[i] = '*';
            }
        }
        
        // Remove all '*' symbols
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
};

