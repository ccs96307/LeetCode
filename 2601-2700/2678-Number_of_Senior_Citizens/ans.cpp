class Solution {
public:
    int countSeniors(vector<string>& details) {
        int num = 0;
        for (auto detail: details) {
            if (detail[11] - '0' > 6 || (detail[11] - '0' == 6 && detail[12] != '0')) {
                ++num;
            }
        }

        return num;
    }
};
