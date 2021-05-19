class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Init
        int max_len = 0;
        deque<char> sub_str = {};
        
        // Find the longest length
        for (int i=0; i<s.size(); i++) {
            while (find(sub_str.begin(), sub_str.end(), s[i]) != sub_str.end()) {
                sub_str.pop_front();
            }
            
            sub_str.push_back(s[i]);
            if (sub_str.size() > max_len) {
                max_len = sub_str.size();
            }
        }
        
        return max_len;
    }
};
