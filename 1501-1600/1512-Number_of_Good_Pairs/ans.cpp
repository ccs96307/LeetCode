class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int good = 0;
        unordered_map<int, int> existedNum;

        for (auto& num: nums) {
            good += existedNum[num];
            ++existedNum[num];
        }

        return good;
    }
};
