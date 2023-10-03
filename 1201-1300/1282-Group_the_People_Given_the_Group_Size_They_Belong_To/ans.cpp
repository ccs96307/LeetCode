class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Init
        int maxSize = 0;
        vector<vector<int>> results;
        unordered_map<int, vector<vector<int>>> idx2groupArr;

        // Split
        for (int i=0; i<groupSizes.size(); ++i) {
            int currSize = groupSizes[i];
            maxSize = max(maxSize, currSize);
            bool fit = false;

            for (vector<int>& arr: idx2groupArr[currSize]) {
                if (arr.size() < currSize) {
                    arr.emplace_back(i);
                    fit = true;
                    break;
                }
            }

            if (!fit) {
                vector<int> newArr({i});
                idx2groupArr[currSize].emplace_back(newArr);
            }
        }

        // Format
        for (int size=1; size<=maxSize; ++size) {
            for (vector<int>& arr: idx2groupArr[size]) {
                results.emplace_back(arr);
            }
        }

        return results;
    }
};

