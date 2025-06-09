class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counter;

        for (char &c: ransomNote) {
            --counter[c];
        }

        for (char &c: magazine) {
            ++counter[c];
        }

        for (auto& [ c, num ]: counter) {
            if (num < 0) {
                return false;
            }
        }

        return true;
    }
};

