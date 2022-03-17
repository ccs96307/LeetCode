class Solution {
public:
    int scoreOfParentheses(string s) {
        // Init
        int score = 0;
        stack<int> st;
        
        // Traversal
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                st.push(0);
            }
            else {
                int temp = 0;

                // If the top is number
                while (!st.empty() && st.top() != 0) {
                    temp += st.top();
                    st.pop();
                }
                
                // If we finally get the top is '('
                st.pop();
                
                // The number need to times 2, and the lowest one is 1
                temp = max(1, temp*2);
                
                // We need to store the temp value into stack
                st.push(temp);                
            }
        }
        
        // Computation
        while (!st.empty()) {
            score += st.top();
            st.pop();
        }
        
        return score;
    }
};

