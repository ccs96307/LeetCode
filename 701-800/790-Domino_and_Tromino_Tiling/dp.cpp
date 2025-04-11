class Solution {
public:
    int numTilings(int n) {
        long long mod = 1e9 + 7;
        vector<long long> results({1, 1, 2});

        for (int i=2; i<n; ++i) {
            results.emplace_back((results[i]*2+results[i-2]) % mod);
        }

        return results[n];
    }
};

