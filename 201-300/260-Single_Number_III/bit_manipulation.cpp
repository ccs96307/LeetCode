class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorsum = 0;

        for (int &num: nums) {
            xorsum ^= num; 
        }

        long long diff = xorsum & (-xorsum);

        vector<int> singles(2, 0);
        for (int &num: nums) {
            if ((num & diff) == 0) {
                singles[0] ^= num;
            }
            else {
                singles[1] ^= num;
            }
        }

        return singles;
    }
};

