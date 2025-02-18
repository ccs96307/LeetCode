class Solution {
public:
    string smallestNumber(string pattern) {
        // Init
        int repeatD = 0;
        std::string str = "123456789";
        
        // Resize
        str.resize(pattern.size() + 1);

        // Detect where need to reverse
        for (int i=0; i<pattern.size(); ++i) {
            if (pattern[i] == 'D') {
                ++repeatD;
            }
            else if (pattern[i] == 'I' && repeatD != 0) {
                std::reverse(str.begin() + i - repeatD, str.begin() + i + 1);
                repeatD = 0;
            }
        }

        // If still need to reverse
        if (repeatD != 0) {
            std::reverse(str.end()-repeatD-1, str.end());
        }

        return str;
    }
};

