class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftHeightest = 0;
        int rightHeightest = 0;

        while (left < right) {
            if (height[left] >= height[right]) {
                if (height[right] >= rightHeightest) {
                    rightHeightest = height[right];
                }
                else {
                    water += rightHeightest - height[right];
                }
                --right;
            }
            else {
                if (height[left] >= leftHeightest) {
                    leftHeightest = height[left];
                }
                else {
                    water += leftHeightest - height[left];
                }
                ++left;
            }
        }

        return water;
    }
};
