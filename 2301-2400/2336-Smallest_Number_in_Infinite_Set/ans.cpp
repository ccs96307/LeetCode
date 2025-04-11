class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SmallestInfiniteSet() {
        for (int i=1; i<=1000; ++i) {
            addBack(i);
        }
    }
    
    int popSmallest() {
        int small = pq.top();
        pq.pop();

        while (!pq.empty() && small == pq.top()) {
            pq.pop();
        }

        return small;
    }
    
    void addBack(int num) {
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
