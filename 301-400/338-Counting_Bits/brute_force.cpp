class Solution {
public:
    vector<int> countBits(int n) {
        // Init
        vector<int> results({0});
        
        // Count
        for (int i=1; i<=n; ++i) {
            int oneNum = 0;
            int num = i;
            
            while (num > 0) {
                oneNum += num % 2;
                num /= 2;
            }
            
            results.push_back(oneNum);
        }
        
        return results;
    }
};

