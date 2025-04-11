class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Prevatation
        if (numRows == 1) return {{1}};
        else if (numRows == 2) return {{1}, {1, 1}};
        
        // Init
        vector<vector<int>> results;
        vector<int> tempResult;
        
        results.push_back({1});
        results.push_back({1, 1});
        
        // Find
        for (int i=3; i<=numRows; ++i) {            
            for (int j=0; j<i; ++j) {
                if (j == 0 || j == i-1) {
                    tempResult.push_back(1);
                }
                else {
                    tempResult.push_back(results[i-2][j-1]+results[i-2][j]);
                }
            }
            
            results.push_back(tempResult);
            tempResult.clear();
        }
        
        return results;
    }
};

