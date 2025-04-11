class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Init
        int left = 0;
        std::string temp;

        // Remove right
        for (char c: s) {
            if (c == '(') {
                ++left;
                temp.push_back(c);
            }
            else if (c == ')') {
                if (left > 0) {
                    --left;
                    temp.push_back(c);
                }
            }
            else {
                temp.push_back(c);
            }
        }

        // Remove left
        int right = 0;
        std::vector<char> result;
        for (int i=temp.size()-1; i>=0; --i) {
            char c = temp[i];
            if (c == ')') {
                ++right;
                result.emplace_back(c);
            }
            else if (c == '(') {
                if (right > 0) {
                    --right;
                    result.emplace_back(c);
                }
            }
            else {
                result.emplace_back(c); 
            }
        }

        // Reverse
        std::reverse(result.begin(), result.end());
        std::string str(result.begin(), result.end());

        return str;
    }
};

