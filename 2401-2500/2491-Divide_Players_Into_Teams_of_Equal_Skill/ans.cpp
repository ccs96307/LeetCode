class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Sort
        sort(skill.begin(), skill.end());
        
        // Init
        long long sum = skill.front() * skill.back();
        int teamNum = skill.front() + skill.back();
        int left = 1;
        int right = skill.size() - 2;
        
        while (left < right) {
            if (skill[left] + skill[right] != teamNum) {
                return -1;
            }
            
            sum += skill[left] * skill[right];
            ++left;
            --right;
        }
        
        return sum;
    }
};

