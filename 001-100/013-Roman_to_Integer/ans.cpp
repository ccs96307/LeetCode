class Solution {
public:
    int romanToInt(string s) {
        // Init
        unordered_map<char, int> r2v= {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int total_val = 0;
        int last_val = 0;
        int current_val = 0;
        
        while (!s.empty()) {
            current_val = r2v[s.back()];
            s.pop_back();
            
            if (current_val >= last_val) {
                total_val += current_val;
            }
            else {
                total_val -= current_val;
            }
            
            last_val = current_val;
        }
        
        return total_val;
    }
};
