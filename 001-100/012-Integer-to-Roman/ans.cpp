class Solution {
public:
    string intToRoman(int num) {
        // Init
        vector<string> symbol({"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"});
        vector<int> nums({1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1});
        string result;
        
        // Loop to combine the answer
        for (int i=0; i<nums.size(); i++) {
            if (num >= nums[i]) {
                for (int n=0; n<(num/nums[i]); n++) {
                    result += symbol[i];
                }
                num = num % nums[i];
            }
        }
        
        return result;
    }
};
