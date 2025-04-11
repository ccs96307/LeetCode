class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Init
        int si = 0;
        int ti = 0;
        
        // Compute the string answer
        for (int i=0; i<s.size(); ++i) {
            if (s[i] != '#') {                
                // Move the keep character to the index `si`
                s[si] = s[i];
                
                // Increase the string length
                ++si;
            }   
            // Backspace
            else if (si > 0) --si;
        }
        
        // Compute the target answer
        for (int i=0; i<t.size(); ++i) {
            if (t[i] != '#') {                
                // Move the keep character to the index `ti`
                t[ti] = t[i];
                
                // Increase the target length
                ++ti;
            }   
            // Backspace
            else if (ti > 0) --ti;
        }
        
        // If length not match
        if (si != ti) return false;
        
        for (int i=0; i<si; ++i) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        
        return true;
    }
};

