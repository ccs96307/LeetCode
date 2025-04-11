class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Init
        int partSize = part.size();
        std::vector<char> result;

        // Check
        for (char& c: s) {
            result.emplace_back(c);

            if (result.size() >= partSize && std::equal(result.end() - partSize, result.end(), part.begin())) {
                result.resize(result.size() - partSize);
            }
        }

        return std::string(result.begin(), result.end());
    }
};

