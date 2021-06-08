class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Preventation
        if (digits.empty()) return {};

        // Init
        vector<string> results;
        vector<int> index_carry(digits.size());
        vector<int> indices(digits.size());

        unordered_map<char, vector<char>> d2s = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };

        while (true) {
            string temp_str = "";
            for (int i=0; i<digits.size(); i++) {
                temp_str += d2s[digits[i]][indices[i]];
            }

            results.push_back(temp_str);

            // Carry
            indices[0] += 1;
            for (int i=0; i<indices.size(); i++) {
                if (indices[i] == d2s[digits[i]].size()) {
                    if (i == indices.size()-1) {
                        return results;
                    }
                    else {
                        indices[i] = 0;
                        indices[i+1] += 1;
                    }
                }
            }
        }

        return results;

    }
};