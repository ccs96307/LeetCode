class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // Init
        vector<vector<int>> results({{}});
        vector<vector<int>> answer;

        for (int i=1; i<=n; ++i) {
            vector<vector<int>>result = results;
            for (int j=0; j<result.size(); ++j) {
                result[j].emplace_back(i);
            }

            results.insert(results.end(), result.begin(), result.end());
        }

        // Get the answers
        for (auto& res: results) {
            if (res.size() == k) {
                answer.emplace_back(res);
            }
        }

        return answer;
    }
};
