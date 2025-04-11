class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Init
        vector<vector<int>> in_out(n, vector<int>(2, 0));
        vector<int> judge({n-1, 0});
        
        // Count
        for (int i=0; i<trust.size(); ++i) {
            ++in_out[trust[i][0]-1][1];
            ++in_out[trust[i][1]-1][0];
        }
        
        // Match
        for (int i=0; i<in_out.size(); ++i) {
            if (in_out[i] == judge) return i+1;
        }
        
        return -1;
    }
};

