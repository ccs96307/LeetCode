class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // init
        int mod = 1e9 + 7;
        long sum = 0;
        stack<int> st;
        vector<int> dp(arr.size());
        
        for (int i=0; i<arr.size(); ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            if (!st.empty()) {
                dp[i] = dp[st.top()] + (i-st.top()) * arr[i];
            }
            else {
                dp[i] = (i+1) * arr[i];
            }
            
            sum = (sum + dp[i]) % mod;
            st.push(i);
        }
        
        return sum;
    }
};

