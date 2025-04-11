class Solution {
public:
    string clearDigits(string s) {
        // Init
        int low = int('0');
        int high = int('9');
        std::stack<char> st;
        std::string result;

        for (const char& c: s) {
            if (!st.empty() && c >= low && c <= high) {
                char top = st.top();
                if (top < int('0') || top > int('9')) {
                    st.pop();
                }
            }
            else {
                st.push(c);
            }
        }

        // Reform
        while (!st.empty()) {
            result += st.top();
            st.pop(); 
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

