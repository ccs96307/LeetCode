class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Init
        string answer;

        // Cantor's Diagonal Argument
        for (int i=0; i<nums.size(); ++i) {
            answer.push_back(nums[i][i] == '0' ? '1' : '0');
        }

        return answer;
    }
};

