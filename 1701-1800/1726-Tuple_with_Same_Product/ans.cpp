class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Init
        int tupleNum = 0;
        unordered_map<int, int> product2times;

        // Count the duplicate products
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                ++product2times[nums[i] * nums[j]];
            }
        }

        // Count the tuple number
        for (const auto& [product, count] : product2times) {
            if (count > 1) {
                tupleNum += 4 * (count * (count - 1));
            }
        }

        return tupleNum;
    }
};

