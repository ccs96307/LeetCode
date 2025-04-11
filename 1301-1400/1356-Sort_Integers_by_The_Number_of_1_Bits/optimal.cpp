class Solution {
public:
    static bool compare(const int& a, const int& b) {
        int aBits = std::bitset<32>(a).count();
        int bBits = std::bitset<32>(b).count();

        return (aBits == bBits) ? (a < b) : (aBits < bBits);
    }

    vector<int> sortByBits(vector<int>& arr) {
        // Sort
        std::sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

