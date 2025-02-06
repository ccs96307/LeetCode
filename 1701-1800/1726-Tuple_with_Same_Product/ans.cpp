class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Init
        int tupleNum = 0;
        unordered_map<int, int> product2times;

        // Count the duplicate products
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                product2times[nums[i] * nums[j]] += 1;
            }
        }

        // Count the tuple number
        for (auto &it: product2times) {
            if (it.second > 1) {
                tupleNum += 4 * (it.second * (it.second - 1));
            }
        }

        return tupleNum;
    }
};

