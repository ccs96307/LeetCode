class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Init
        vector<bool> selected(26, false);
        vector<int> count(26, 0);
        stack<int> st;
        
        // Count
        for (auto& c: s) {
            ++count[c-'a'];
        }
        
        // Selection
        for (auto c: s) {
            --count[c-'a'];
            
            // If we had selected the current character, we can skip it
            if (selected[c-'a']) continue;
            
            // Make sure the smallest in lexicographical order
            while (!st.empty() && st.top()>c && count[st.top()-'a']>0) {
                selected[st.top()-'a'] = false;                
                st.pop();
            }
            
            st.push(c);
            selected[c-'a'] = true;            
        }
        
        // Answer
        string answer;
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
        
        // Reverse
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};

