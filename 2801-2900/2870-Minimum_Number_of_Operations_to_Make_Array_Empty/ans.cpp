class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Init
        int steps = 0;
        unordered_map<int, int> counter;

        // Count
        for (int& num: nums) {
            ++counter[num];
        }

        // Check steps
        for (auto& it: counter) {
            int value = it.second;
            if (value == 1) {
                return -1;
            }
            else if (value % 3 == 1) {
                steps += value / 3 - 1;  // value / 3 = step...1, and 1 + 3 = 4, step -= 1,
                steps += 2;  // 4 / 2 = 2
            }
            else {
                steps += value / 3;
                steps += value % 3 / 2;
            }
        }

        return steps;
    }
};

