class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = 0;
        int i2 = 0;

        while (i2 < nums2.size()) {
            if (i1 >= nums1.size()) {
                nums1.emplace_back(nums2[i2]);
                ++i2;
            }
            else if (nums1[i1] == 0) {
                nums1[i1] = nums2[i2];
                ++i2;
            }
            
            ++i1;
        }

        sort(nums1.begin(), nums1.end());
    }
};

