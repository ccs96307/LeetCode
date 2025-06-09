class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int latestIdx = 0;
        unordered_map<string, int> mp;
        vector<vector<string>> results(strs.size());

        for (string str: strs) {
            string ori = str;
            sort(str.begin(), str.end());

            if (!mp.count(str)) {
                mp[str] = latestIdx;
                results[latestIdx].emplace_back(ori);
                ++latestIdx;
            }
            else {
                int idx = mp[str];
                results[idx].emplace_back(ori);
            }
        }

        results.resize(latestIdx);

        return results;
    }
};

