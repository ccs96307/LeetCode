class Solution {
public:
    string countAndSay(int n) {
        // Init
        int times = 1;
        string s = "1";
        
        // Unfold
        while (times < n) {
            ++times;
            char c = '0';
            vector<char> vc;
            vector<int> vcn;
            
            // Count the numbers of repeat characters
            for (int i=0; i<s.size(); ++i) {
                if (s[i] != c) {
                    c = s[i];
                    vc.push_back(s[i]);
                    vcn.push_back(1);
                }
                else {
                    ++vcn[vc.size()-1];
                }
            }
            
            // Clear the current string
            s.clear();
            
            // Create the new string
            for (int i=0; i<vc.size(); ++i) {
                s += to_string(vcn[i]);
                s += vc[i];
            }
        }
        
        return s;
    }
};

