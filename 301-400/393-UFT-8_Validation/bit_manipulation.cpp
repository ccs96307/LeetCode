class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // Init
        int currMaxN = 0;

        // Determined        
        for (int i=0; i<data.size(); ++i) {
            // Count 1's
            if (currMaxN == 0) {
                if (data[i] >> 5 == 0b110) {
                    currMaxN = 1;
                }
                else if (data[i] >> 4 == 0b1110) {
                    currMaxN = 2;
                }
                else if (data[i] >> 3 == 0b11110) {
                    currMaxN = 3;
                } 
                else if (data[i] >> 7 != 0) {
                    return false;
                }
            }
            else {
                if (data[i] >> 6 == 0b10) {
                    --currMaxN;
                }
                else {
                    return false;
                }
            }
        }
        
        return currMaxN == 0;
    }
};

