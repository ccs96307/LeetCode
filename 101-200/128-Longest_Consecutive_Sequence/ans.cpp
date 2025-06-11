class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        set<int> sets(nums.begin(), nums.end());

        for (int num: sets) {
            if (sets.count(num-1)) {
                continue;
            }

            int length = 1;
            int curr = num + 1;

            while (true) {
                if (sets.count(curr)) {
                    ++length;
                    ++curr;
                }
                else {
                    break;
                }
            }

            longest = max(longest, length);
        }

        return longest;
    }
};

