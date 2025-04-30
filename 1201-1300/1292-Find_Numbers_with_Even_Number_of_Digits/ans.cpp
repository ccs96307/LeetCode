class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenNum = 0;

        for (int num: nums) {
            bool isEven = true;
            while (num != 0) {
                num /= 10;
                isEven = !isEven;
            }

            if (isEven) {
                ++evenNum;
            }
        }

        return evenNum;
    }
};

