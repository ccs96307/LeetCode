class Solution {
public:
    int reverse(int x) {
        // Init
        string s = std::to_string(x);
                
        if (s[0] == '-' and s.size() > 2) {
            std::reverse(s.begin(), s.end());
            s.pop_back();
            s = '-' + s;
            if (std::stoi(s.substr(0, s.size()-1)) < INT_MIN/10) return 0;
            if (std::stoi(s.substr(0, s.size()-1)) == INT_MIN/10 and std::stoi(s.substr(s.size()-1, 1)) > 8) return 0;

        }
        else if (s.size() > 1) {
            std::reverse(s.begin(), s.end());
            if (std::stoi(s.substr(0, s.size()-1)) > INT_MAX/10) return 0;
            if (std::stoi(s.substr(0, s.size()-1)) == INT_MAX/10 and std::stoi(s.substr(s.size()-1, 1)) > 7) {
                return 0;
            }
        }
        
        return std::stoi(s);
    }
};
