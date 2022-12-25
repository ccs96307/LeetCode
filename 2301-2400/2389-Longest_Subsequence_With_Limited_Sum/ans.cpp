class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Sort the `nums`
        sort(nums.begin(), nums.end());

        // Init
        vector<int> results;

        // Accumulate the number of `nums` until the accumulation is larger than query
        for (int& query: queries) {
            int steps = 0;
            int sum = 0;
            for (int i=0; i<nums.size(); ++i) {
                sum += nums[i];
                if (sum > query) {
                    break;
                }
                ++steps;
            }
            results.emplace_back(steps);
        }

        return results;
    }
};

