class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Init
        int total = 0;
        int GNum = 0;
        int PNum = 0;
        int MNum = 0;

        // Count every types of garbages
        for (string& g: garbage) {
            for (char& c: g) {
                if (c == 'M') {
                    ++MNum;
                }
                else if (c == 'P') {
                    ++PNum;
                }
                else if (c =='G'){
                    ++GNum;
                }
            }
        }

        // Count the total times
        int currG = 0;
        int currP = 0;
        int currM = 0;
        for (int i=0; i<garbage.size(); ++i) {
            if (i != 0) {
                if (currG < GNum) {
                    total += travel[i-1];
                }
                if (currP < PNum) {
                    total += travel[i-1];
                }
                if (currM < MNum) {
                    total += travel[i-1];
                }
            }

            for (int j=0; j<garbage[i].size(); ++j) {
                if (garbage[i][j] == 'G') {
                    ++currG;
                }
                else if (garbage[i][j] == 'P') {
                    ++currP;
                }
                else if (garbage[i][j] == 'M') {
                    ++currM;
                }
            }
        }

        return total + GNum + PNum + MNum;
    }
};

