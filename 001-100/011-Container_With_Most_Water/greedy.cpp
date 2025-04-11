class Solution {
public:
    int maxArea(vector<int>& height) {
        // Init
        int maxVol = 0;
        int left = 0;
        int right = height.size() - 1;
        
        // Finding
        while (left < right) {
            maxVol = max(min(height[left], height[right])*(right-left), maxVol);
            
            // Step
            if (height[left] < height[right]) {
                ++left;
            }
            else if (height[left] > height[right]) {
                --right;
            }
            else {
                ++left;
                --right;
            }
        }
        
        return maxVol;
    }
};

