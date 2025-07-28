class Solution {
public:
    int trap(vector<int>& height) {
        int h = 0;
        vector<int> waters(height.size(), 0);

        for (int i=0; i<height.size(); ++i) {
            if (h > height[i]) {
                waters[i] = h - height[i];
            }
            else {
                h = height[i];
            }
        }

        h = 0;
        for (int i=height.size()-1; i>=0; --i) {
            int temp = h - height[i];
            if (temp > 0) {
                waters[i] = min(waters[i], temp);
            }
            else {
                h = height[i];
                waters[i] = 0;
            }
        }

        return std::accumulate(waters.begin(), waters.end(), 0);
    }
};
