class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        
        vector<string> v(numRows, "");
        int carry = 1;
        int save_pos = 0;
        
        for (char w: s) {
            if (save_pos == 0) {
                carry = 1;
            }
            else if (save_pos == numRows-1) {
                carry = -1;
            }
            
            v[save_pos] += (w);
            save_pos += carry;
        }
        
        string results;
        for (int i=0; i<v.size(); i++) {
            for (int n: v[i]) {
                results += n;
            }
        }
        
        return results;
    }
};
