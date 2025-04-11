class Solution {
public:
    string makeGood(string s) {
        // Init
        stack<char> st;

        // Remove duplicated characters
        for (int i=0; i<s.size(); ++i) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }

            if (std::isupper(s[i])) {
                if (std::islower(st.top())) {
                    if (s[i] - 'A' == st.top() - 'a') {
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }
            else {
                if (std::isupper(st.top())) {
                    if (s[i] - 'a' == st.top() - 'A') {
                        st.pop();
                        continue;
                    }
                }
                st.push(s[i]);
            }
        }

        // Re-combined
        string results = "";
        while (!st.empty()) {
            results = st.top() + results;
            st.pop();
        }

        return results;
    }
};

