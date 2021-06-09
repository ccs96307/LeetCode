class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        for (int n: nums) {
            if (n != val) {
                nums[p] = n;
                p++;
            }
        }
        return p;
    }
};