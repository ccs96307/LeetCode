class Solution {
public:
    string simplifyPath(string path) {
        // Init
        vector<string> v;
        string part;
        stringstream ss(path);

        // Get the part of splited string by '/'
        while (getline(ss, part, '/')) {
            // If it is empty or represented by current directory
            if (part == "" || part == ".") {
                continue;
            } 
            // If it is jump back to the previous directory
            else if (part == "..") {
                if (!v.empty()) {
                    v.pop_back();
                }
            } 
            else {
                v.emplace_back(part);
            }
        }

        string result;
        for (const auto& dir: v) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};


