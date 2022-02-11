class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Base case
        if (s1.size() > s2.size()) return false;
        
        // Init
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        // Prepare v1 and v2
        for (int i=0; i<s1.size(); ++i) {
            ++v1[int(s1[i])-97];
            ++v2[int(s2[i])-97];
        }
        
        // First match
        if (v1 == v2) return true;
        
        // For-loop match
        for (int i=0; i<s2.size()-s1.size(); ++i) {
            --v2[int(s2[i])-97];
            ++v2[int(s2[i+s1.size()])-97];
            
            if (v1 == v2) return true;
        }
        
        // If not match case, return false
        return false;
    }
};
