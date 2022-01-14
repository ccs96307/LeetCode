class Solution {
public:
    int myAtoi(string s) {
        // Init
        long ans = 0;
        int sign = 0;
        string nums;
        unordered_map<char, int> c2i({
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9},                 
        });
        
        // Run
        for (int i=0; i<s.size(); ++i) {
            if (sign == 0) {
                if (s[i] == '+') sign = 1;
                else if (s[i] == '-') sign = -1;
                else if (isdigit(s[i])) {
                    sign = 1;
                    nums += s[i];
                }
                else if (s[i] == ' ') continue;
                else return 0;
            } 
            else {
                if (isdigit(s[i])) {
                    nums += s[i];
                }
                else break;
            }
        }
        
        // Convert to numbers
        for (int i=0; i<nums.size(); ++i) {            
            ans = ans * 10 + sign * c2i[nums[i]];
            
            if (ans > INT_MAX) return INT_MAX;
            else if (ans < INT_MIN) return INT_MIN;
        }
        
        // Return
        return ans;
    }
};
