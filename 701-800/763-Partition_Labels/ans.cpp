class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Init
        int start = 0;
        int end = 0;
        vector<int> end_idx(26, 0);
        vector<int> results;
        
        // Record the last position of character
        for (int i=0; i<s.size(); ++i) {
            end_idx[s[i]-'a'] = i;
        }
        
        // Scanning string character
        for (int i=0; i<s.size(); ++i) {
            end = max(end, end_idx[s[i]-'a']);
            
            if (i == end) {
                results.push_back(i-start+1);
                start = i + 1;
            }
        }
        
        return results;
    }
};

