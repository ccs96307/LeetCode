class FreqStack {
public:
    // Init
    int maxFreq = 0;
    unordered_map<int, int> val2freq;
    unordered_map<int, stack<int>> freq2stack;
    
    FreqStack() {
        
    }
    
    // Push09sxaz
    void push(int val) {
        ++val2freq[val];
        maxFreq = max(maxFreq, val2freq[val]);
        
        freq2stack[val2freq[val]].push(val);
    }
    
    int pop() {
        // Get the top value
        int top = freq2stack[maxFreq].top();
        freq2stack[maxFreq].pop();
        
        // Decrement the frquency of the top value (for the next push)
        --val2freq[top];
        
        // If the maxFreq stack has no any value
        if (freq2stack[maxFreq].empty()) --maxFreq;
        
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

