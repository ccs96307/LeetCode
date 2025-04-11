class Solution {
public:    
    bool isValid(string s) {
        // Init
        stack<char> st;
        
        // Matching
        for (char c: s) {            
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if (st.empty()) {
                return false;
            }            
            else if (st.top() == '(' && c != ')') return false;
            else if (st.top() == '{' && c != '}') return false;
            else if (st.top() == '[' && c != ']') return false;
            
            // Pop
            else st.pop();
        }
        
        return (st.empty());
    }
};

