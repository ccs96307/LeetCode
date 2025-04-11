class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Init
        stack<long> st;

        for (auto& token: tokens) {
            if (token == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b+a);
            }
            else if (token == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if (token == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push((long)b*a);
            }
            else if (token == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

