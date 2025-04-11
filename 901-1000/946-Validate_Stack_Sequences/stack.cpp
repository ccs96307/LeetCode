class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Init
        int pop_i = 0;
        stack<int> st;

        // Detect the top of stack eqaul to the current popped element
        for (int i=0; i<pushed.size(); ++i) {
            st.push(pushed[i]);

            while (!st.empty() && popped[pop_i] == st.top()) {
                st.pop();
                ++pop_i;
            }
        }

        return st.empty();
    }
};

