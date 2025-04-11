class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int maxLevel = 0;
        unordered_map<int, int> count;
        unordered_map<int, int> num2level;
        
        for (auto& n: arr) {
            ++num2level[n];
            ++count[num2level[n]];
            --count[num2level[n]-1];
            
            maxLevel = max(num2level[n], maxLevel);
        }
        
        int reduceTimes = 0;
        int currLength = arr.size();
        int targetLength = arr.size() / 2;
    
        while (currLength > targetLength) {
            ++reduceTimes;
            currLength -= maxLevel;
            --count[maxLevel];
            
            while (count[maxLevel] == 0) {
                --maxLevel;
            }
        }
        
        return reduceTimes;
    }
};

