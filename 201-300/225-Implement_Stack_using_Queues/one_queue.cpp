class MyStack {
public:
    std::queue<int> q;

    MyStack() {

    }
    
    void push(int x) {
        q.push(x);

        // Reverse
        for (int i=0; i<q.size()-1; ++i) {
            int popVal = q.front();
            q.pop();
            q.push(popVal);
        }
    }
    
    int pop() {        
        int popVal = q.front();
        q.pop();

        return popVal;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

