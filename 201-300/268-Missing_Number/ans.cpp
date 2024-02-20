class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ori = (nums.size() + 1) * nums.size() / 2;
        int cur = std::accumulate(nums.begin(), nums.end(), 0);
        return ori - cur;
    }
};

