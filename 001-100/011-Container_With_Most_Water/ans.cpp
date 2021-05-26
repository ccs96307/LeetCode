class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int left = 0;
        int right = height.size()-1;
        
        while (left < right) {
            int temp_vol = 0;
            if (height[left] > height[right]) {
                temp_vol = height[right] * (right - left);
                if (temp_vol > max_vol) max_vol = temp_vol;
                --right;
            }
            else if (height[left] < height[right]) {
                temp_vol = height[left] * (right - left);
                if (temp_vol > max_vol) max_vol = temp_vol;
                ++left;
            }
            else if (height[left] == height[right]) {
                temp_vol = height[right] * (right - left);
                if (temp_vol > max_vol) max_vol = temp_vol;
                --right;
                ++left;
            }            
        }
        
        return max_vol;
    }
};

