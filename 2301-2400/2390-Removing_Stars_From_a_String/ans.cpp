class Solution {
public:
    string removeStars(string s) {
        // Init
        vector<char> v;

        // Detect '*' and pop the previous character
        for (char c: s) {
            if (c != '*') {
                v.emplace_back(c);
            }
            else {
                v.pop_back();
            }
        }

        // Convert `vector` into `string`
        string result(v.begin(), v.end());
        return result;
    }
};

