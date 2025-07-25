class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> counts;
        unordered_map<int, int> ends;

        for (int& num: nums) {
            ++counts[num];
        }

        for (int num: nums) {
            if (counts[num] == 0) {
                continue;
            }

            if (ends[num - 1] > 0) {
                --ends[num - 1];
                ++ends[num];
                --counts[num];
            }
            else if (counts[num + 1] >= 1 && counts[num + 2] >= 1) {
                ++ends[num + 2];
                --counts[num];
                --counts[num + 1];
                --counts[num + 2];
            }
            else {
                return false;
            }
        }

        return true;
    }
};

