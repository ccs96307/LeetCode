class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int> v(n*2, 0);
        vector<string> temp_results;

        while (true) {
            v[0] += 1;
            for (int i=0; i<v.size(); i++) {
                if (v[i] == 2) {
                    v[i] = 0;
                    v[i+1]++;
                }
            }

            // int 2 string
            string temp_str;
            for (int n: v) {
                if (n == 0) temp_str += '(';
                else temp_str += ')';
            }

            temp_results.push_back(temp_str);

            if (find(v.begin(), v.end(), 0) == v.end()) {
                break;
            }
        }

        // Remove wrong case
        vector<string> results;
        for (int i=0; i<temp_results.size(); i++) {
            vector<char> v;

            for (char w: temp_results[i]) {
                v.push_back(w);
                bool keep = true;
                while (keep and v.size() > 1) {
                    keep = false;
                    if (v[v.size()-1] == ')' and v[v.size()-2] == '(') {
                        v.pop_back();
                        v.pop_back();
                        keep = true;
                    }
                }
            }
            if (v.empty()) {
                results.push_back(temp_results[i]);
            }
        }

        return results;
    }
};