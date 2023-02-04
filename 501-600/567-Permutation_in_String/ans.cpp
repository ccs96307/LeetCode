class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Base case
        if (s1.size() > s2.size()) {
            return false;
        }

        // Init
        vector<int> counter1(26, 0);
        vector<int> counter2(26, 0);

        // Compare s1 and s2
        for (int i=0; i<s1.size(); ++i) {
            ++counter1[s1[i]-'a'];
            ++counter2[s2[i]-'a'];
        }
        if (counter1 == counter2) {
            return true;
        }

        // Sliding matching
        int left = 0;
        int right = s1.size();
        while (right < s2.size()) {
            --counter2[s2[left]-'a'];
            ++counter2[s2[right]-'a'];

            if (counter1 == counter2) {
                return true;
            }

            ++left;
            ++right;
        }

        return false;
    }
};

