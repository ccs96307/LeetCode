class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // Init
        int currMaxN = 0;

        // Determined        
        for (int i=0; i<data.size(); ++i) {
            int currN = 0;
            string s = bitset<8>(data[i]).to_string();
                        
            // Count 1's
            for (int j=0; j<s.size(); ++j) {
                if (s[j] == '1') {
                    ++currN;
                }
                else {
                    break;
                }
            }
                        
            if (currMaxN == 0) {
                if (currN == 1) {
                    return false;
                }
                else if (currN > 1) {
                    currMaxN = currN - 1;
                }
            }
            else if (currMaxN > 0) {
                if (currN == 1) {
                    --currMaxN;
                }
                else {
                    return false;
                }
            }
            
            if (currMaxN >= 4) {
                return false;
            }
        }
        
        return currMaxN == 0;
    }
};

