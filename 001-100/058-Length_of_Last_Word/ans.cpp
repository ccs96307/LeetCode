class Solution {
public:
    int lengthOfLastWord(string s) {
        // Find the start point
        int start_idx = s.size() - 1;
        while (s[start_idx] == ' ') {
            --start_idx;
        }

        // Find the end point
        int end_idx = start_idx - 1;
        while (end_idx >= 0 && s[end_idx] != ' ') {
            --end_idx;
        }

        return start_idx - end_idx;
    }
};
