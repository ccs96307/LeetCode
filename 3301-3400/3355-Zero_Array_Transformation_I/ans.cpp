class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int _size = nums.size();
        vector<int> count(_size+1, 0);

        for (int i=0; i<queries.size(); ++i) {
            int left = queries[i][0];
            int right = queries[i][1];

            ++count[left];
            if (right + 1 < _size) {
                --count[right + 1];
            }
        }

        int accumulation = 0;
        for (int i=0; i<nums.size(); ++i) {
            accumulation += count[i];

            if (accumulation < nums[i]) {
                return false;
            }
        }

        return true;
    }
};

