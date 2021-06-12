class Solution {
public:
    int strStr(string haystack, string needle) {
        // Prevention
        if (needle.empty()) {
            return 0;
        }
        
        if (needle.size() > haystack.size()) {
            return -1;
        }
        
        // Init
        bool hit = false;
        
        for (int i=0; i<haystack.size()-needle.size()+1; i++) {
            hit = true;
            for (int j=0; j<needle.size(); j++) {
                if (haystack[i+j] != needle[j]) {
                    hit = false;
                    break;
                }
            }
            if (hit) return i;
        }
        return -1;
    }
};

