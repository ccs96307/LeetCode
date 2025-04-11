class Solution {
public:
    int jump(vector<int>& nums) {
        // Base case
        if (nums.size() == 1) {
            return 0;
        }

        // Init
        int steps = 1;
        queue<int> q({0});
        unordered_map<int, bool> visited;

        // Jumping
        while (!q.empty()) {
            int _size = q.size();

            for (int i=0; i<_size; ++i) {
                int idx = q.front();
                q.pop();

                if (visited[idx]) {
                    continue;
                }
                visited[idx] = true;

                // If reach the goal, return the answer `steps`
                if (nums[idx] + idx >= nums.size() - 1) {
                    return steps;
                }

                for (int j=1; j<=nums[idx]; ++j) {
                    q.push(idx+j);
                }
            }

            ++steps;
        }

        return steps;
    }
};

