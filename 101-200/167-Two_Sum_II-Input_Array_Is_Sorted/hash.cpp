class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> remain2idx;
        vector<int> results;

        for (int i=0; i<numbers.size(); ++i) {
            if (remain2idx.count(numbers[i])) {
                results.emplace_back(remain2idx[numbers[i]]+1);
                results.emplace_back(i+1);
                break;
            }

            remain2idx[target - numbers[i]] = i;
        }

        return results;
    }
};
