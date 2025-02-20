class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Init
        int bitLen = nums[0].size();
        string answer;
        std::unordered_set<string> set(nums.begin(), nums.end());

        // Find
        for (int i=0; i<pow(2, bitLen); ++i) {
            std::string temp = std::bitset<16>(i).to_string();
            answer = temp.substr(16 - bitLen);

            if (set.find(answer) == set.end()) {
                break;
            }
        }

        return answer;
    }
};

