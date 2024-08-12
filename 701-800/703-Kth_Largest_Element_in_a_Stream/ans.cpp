class KthLargest {
public:
    int K = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > K) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
