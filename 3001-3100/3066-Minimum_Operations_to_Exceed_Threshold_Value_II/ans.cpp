class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Init
        int operations = 0;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());

        // Iter
        while (minHeap.top() < k) {
            ++operations;

            long long _min = minHeap.top();
            minHeap.pop();

            long long _max = minHeap.top();
            minHeap.pop();

            minHeap.push(_min * 2 + _max);
        }

        return operations;
    }
};

