class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Init
        stack<long> st;
        unordered_map<string, bool> opts({
            {"+", true},
            {"-", true},
            {"*", true},
            {"/", true},
        });

        for (auto& token: tokens) {
            if (opts[token]) {
                long a = st.top(); 
                st.pop();
                
                long b = st.top();
                st.pop();

                if (token == "+") {
                    st.push(b+a);
                }
                else if (token == "-") {
                    st.push(b-a);
                }
                else if (token == "*") {
                    st.push(b*a);
                }
                else if (token == "/") {
                    st.push(b/a);
                }
            }
            else {
                st.push(stol(token));
            }
        }

        return st.top();
    }
};

