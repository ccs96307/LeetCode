class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Init
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        // Sort
        sort(nums1.begin(), nums1.end());
        
        // Branch
        if (nums1.size() % 2 == 0) {
            return double(nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2;
        }
        else {
            return double(nums1[nums1.size()/2]);
        }
    }
};
