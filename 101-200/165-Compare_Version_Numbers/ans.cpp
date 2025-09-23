class Solution {
private:
    void trimTailZero(string &ver) {
        while (ver.size() > 1) {
            size_t pos = ver.find_last_of(".");
            if (pos == string::npos) {
                return;
            }

            string tail = ver.substr(pos + 1); // start after '.'
            if (stoi(tail) == 0) {
                ver.erase(pos);
            }
            else {
                return;
            }
        }
    }

    vector<int> splitDotAndSToI(string &ver) {
        vector<int> versions;
        string temp = "";
        for (char c: ver) {
            if (c != '.') {
                temp.push_back(c);
            }
            else {
                versions.emplace_back(stoi(temp));
                temp.clear();
            }
        }

        if (!temp.empty()) {
            versions.emplace_back(stoi(temp));
        }

        return versions;
    }

public:
    int compareVersion(string version1, string version2) {
        trimTailZero(version1);
        trimTailZero(version2);

        vector<int> nums1 = splitDotAndSToI(version1);
        vector<int> nums2 = splitDotAndSToI(version2);

        int minLen = min(nums1.size(), nums2.size());

        for (int i = 0; i < minLen; ++i) {
            if (nums1[i] < nums2[i]) {
                return -1;
            }
            else if (nums1[i] > nums2[i]) {
                return 1;
            }
        }

        if (nums1.size() > nums2.size()) {
            return 1;
        }
        else if (nums1.size() < nums2.size()) {
            return -1;
        }
        
        return 0;
    }
};

