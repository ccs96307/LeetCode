class Solution {
public:
    int maxDifference(string s) {
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        vector<int> counter(26, 0);

        for (char &c: s) {
            ++counter[c-'a'];
        }

        for (int &n: counter) {
            if (n == 0) {
                continue;
            }
            else if (n % 2) {
                maxOdd = max(maxOdd, n);
            }
            else {
                minEven = min(minEven, n);
            }
        }
        
		return maxOdd - minEven;
    }
};

