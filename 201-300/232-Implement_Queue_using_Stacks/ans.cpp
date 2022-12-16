class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        exchange(st1, st2);
        int popVal = st2.top();
        st2.pop();
        exchange(st1, st2);
        return popVal;
    }
    
    int peek() {
        exchange(st1, st2);
        int peekVal = st2.top();
        exchange(st1, st2);

        return peekVal;
    }
    
    bool empty() {
        return st1.empty();
    }

    void exchange(stack<int>& st1, stack<int>& st2) {
        if (!st1.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else {
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

private:
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

