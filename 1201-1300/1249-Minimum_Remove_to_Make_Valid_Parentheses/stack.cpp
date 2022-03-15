class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Init
        stack<int> pos;
        
        // Make valid
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                pos.push(i);
            }
            else if (s[i] == ')') {
                if (pos.empty() || s[pos.top()] != '(') {
                    pos.push(i);
                }
                else {
                    pos.pop();
                }
            }
        }
        
        // Mask
        for (int i=s.size()-1; i>=0; --i) {
            if (!pos.empty() && i == pos.top()) {
                s[i] = '*';
                pos.pop();
            }
        }
        
        // Remove all '*' symbols
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
};


