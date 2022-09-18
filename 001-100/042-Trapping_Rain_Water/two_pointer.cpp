class Solution {
public:
    int trap(vector<int>& height) {
        // Init
        vector<int> vol;
        int tempHeight = 0;
        
        // Left
        for (int i=0; i<height.size(); ++i) {
            tempHeight = max(tempHeight, height[i]);
            vol.push_back(tempHeight-height[i]);
        }
        
        // Right
        tempHeight = 0;
        for (int i=height.size()-1; i>=0; --i) {
            tempHeight = max(tempHeight, height[i]);
            vol[i] = min(vol[i], tempHeight-height[i]);
        }
        
        return accumulate(vol.begin(), vol.end(), 0);
    }
};

