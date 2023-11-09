class Solution {
public:
    long long sum(int n) {
        return (long long)n * ((long long)n + 1) / 2;
    }

    int countHomogenous(string s) {
        // Init
        int mod = pow(10, 9) + 7;
        long long total = 0;
        int accum = 1;
        char prev = s[0];

        // Count the accumulated total number
        for (int i=1; i<s.size(); ++i) {
            if (s[i] == prev) {
                ++accum;
            }
            else {
                total += sum(accum);
                accum = 1;
            }

            prev = s[i];
        }

        // Handle the last sequence
        return (total + sum(accum)) % mod;
    }
};

