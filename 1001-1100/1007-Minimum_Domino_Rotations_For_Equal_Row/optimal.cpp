class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Init
        int minRotation = INT_MAX;
        vector<int> topNums(6, 0);
        vector<int> bottomNums(6, 0);
        vector<int> sameNums(6, 0);
        
        // Count the Domino numbers
        for (int i=0; i<tops.size(); ++i) {
            ++topNums[tops[i]-1];
            ++bottomNums[bottoms[i]-1];
            
            if (tops[i] == bottoms[i]) {
                ++sameNums[tops[i]-1];
            }
        }
        
        // Find the minimum numbers of rotations
        for (int i=0; i<6; ++i) {
            if (topNums[i]+bottomNums[i]-sameNums[i] == tops.size()) {
                int temp = min(topNums[i]-sameNums[i], bottomNums[i]-sameNums[i]);
                minRotation = min(minRotation, temp);
            }
        }
        
        // If minRotation is equal to `INT_MAX`, it means it cannot be done
        return minRotation == INT_MAX ? -1 : minRotation;
    }
};

