class Solution {
public:
    char findTheDifference(string s, string t) {
        int sn = 0;
        int tn = 0;
        
        for (int i=0; i<s.size(); ++i) {
            sn += s[i];
            tn += t[i];
        }
        
        tn += t[t.size()-1];
        
        return char(tn-sn);
    }
};

