class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        // Init
        vector<string> results;
        string result;
        
        // Save substring to results
        for (int i=0; i<s.size(); ++i) {
            result += s[i];
            if (result.size() == k) {
                results.push_back(result);
                result.clear();
            }
        }
        
        // Fill the last result
        while (result.size() != 0 && result.size() < k) {
            result += fill;
            if (result.size() == k) results.push_back(result);
        }
        
        return results;
    }
};

