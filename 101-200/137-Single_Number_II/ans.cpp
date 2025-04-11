class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> appearTable;
        int result;
        
        for (int n: nums) {
            if (appearTable.find(n) == appearTable.end()) {
                appearTable[n] = 1;
            }
            else {
                ++appearTable[n];
                if (appearTable[n] == 3) {
                    appearTable.erase(n);
                }
            }
        }
        
        for (auto n: appearTable) result = n.first; 
        return result;
    }
};

