class Solution {
public:
    string removeStars(string s) {
        // Init
        int i = 0;
        
        // Detect '*' and pass the previous stored character
        for (char c: s) {
            if (c == '*') {
                --i;
            }
            else {
                s[i++] = c;
            }
        }

        // Convert `vector` into `string`
        return s.substr(0, i);
    }
};

