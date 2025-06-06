class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, bool> isExisted;

        for (int &num: nums) {
            if (isExisted[num]) {
                isExisted[num] = false;
            }
            else {
                isExisted[num] = true;
            }
        }

        vector<int> singles;
        for (auto& [ num, isExist ] : isExisted) {
            if (isExist) {
                singles.emplace_back(num);
            }
        }

        return singles;
    }
};

