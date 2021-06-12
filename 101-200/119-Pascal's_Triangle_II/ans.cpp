class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> newRow;
        vector<int> tempRow;
        
        for (int i=0; i<=rowIndex; ++i) {
            if (i == 0) newRow.push_back(1);
            else if (i == 1) {
                newRow.clear();
                newRow.push_back(1);
                newRow.push_back(1);
            }
            else {
                for (int j=0; j<i+1; ++j) {
                    if (j == 0 || j == i) {
                        tempRow.push_back(1);
                    }
                    else {
                        tempRow.push_back(newRow[j-1]+newRow[j]);
                    }
                }
                
                newRow = tempRow;
                tempRow.clear();
            }
        }
        
        return newRow;
    }
};

