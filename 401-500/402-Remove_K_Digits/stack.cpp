class Solution {
public:
    string removeKdigits(string num, int k) {
        // Base case
        if (num.size() == k) return "0";
        
        // Init
        string ans;
        stack<char> s({num[0]});
        
        // Current element need to larger than the next one
        for (int i=1; i<num.size(); ++i) {
            while (k > 0 && !s.empty() && s.top() > num[i]) {
                --k;
                s.pop();
            }
            
            s.push(num[i]);
            
            // Remove the zero at the begin
            if (s.size() == 1 && s.top() == '0') {
                s.pop();
            }
        }
        
        // We still need to remove some elements
        while (k > 0 && !s.empty()) {
            --k;
            s.pop();
        }
        
        // Combine the answer
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        // Reverse
        reverse(ans.begin(), ans.end());
        
        if (ans.size() == 0) return "0";
        else return ans;
    }
};

