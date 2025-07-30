class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        prefix.emplace_back(0);

        int total = 0;
        for (int& num: nums) {
            total += num;
            prefix.emplace_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

