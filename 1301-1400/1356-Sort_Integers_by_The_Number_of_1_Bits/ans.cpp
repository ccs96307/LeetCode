class Solution {
public:
    int getBits(int n) {
        int bits = 0;
        while (n > 0) {
            bits = n % 2 ? bits + 1 : bits;
            n /= 2;
        }
        return bits;
    }

    vector<int> sortByBits(vector<int>& arr) {
        // Init
        vector<int> bits;
        for (int& n: arr) {
            bits.emplace_back(getBits(n));
        }

        // Sort
        for (int i=0; i<arr.size(); ++i) {
            for (int j=0; j<arr.size() - i - 1; ++j) {
                if (bits[j] > bits[j+1] || (bits[j] == bits[j+1] && arr[j] > arr[j+1])) {
                    swap(bits[j], bits[j+1]);
                    swap(arr[j], arr[j+1]);
                }
            }
        }

        return arr;
    }
};

