class Solution {
public:
    int myAtoi(string s) {
        // Preventation
        if (s.empty()) return 0;
        
        // Init
        bool status = false;
        string result;
        
        for (char w: s) {
            if (!status) {
                if (w == ' ') continue;
                else if (isdigit(w) || w == '+' || w == '-') {
                    status = true;
                    result += w;
                }
                else {
                    return 0;
                }
            }
            else {
                if (isdigit(w)) {
                    result += w;
                }
                else {
                    break;
                }
            }
        }
        
        // Remove 0
        while (result[0] == '0') result.erase(0, 1);
        while (!isdigit(result[0]) && result[1] == '0') result.erase(1, 1);
        
        // If result is empty
        if (result.empty()) return 0;
        
        // If result only have sign
        if (result.size() == 1 && !isdigit(result[0])) return 0;
        
        // If result too large
        if (result.size() > 12) {
            if (result[0] == '-') return INT_MIN;
            else return INT_MAX;
        }
        
        // Return answer
        long int ans = std::stol(result);
        
        if (ans > INT_MAX) return INT_MAX;
        else if (ans < INT_MIN) return INT_MIN;
        
        return ans;
    }
};
