class Solution {
public:
    string makeGood(string s) {
        // Init
        std::string results;

        // Removing
        for (char c: s) {
            if (!results.empty() && std::toupper(c) == std::toupper(results.back()) && c != results.back()) {
                results.pop_back();
            }
            else {
                results.push_back(c);
            }
        }

        return results;
    }
};

