class MinStack {
    stack<int> s;
    int Min;
public:
    /** initialize your data structure here. */
    MinStack() {
        Min = INT_MAX;
    }
    
    void push(int x) {
        if(x <= Min) {
            s.push(Min);
            Min = x;
        }
        s.push(x);
    }
    
    void pop() {
        if(s.top() == Min) {
            s.pop();
            Min = s.top();
            s.pop();
        }
        else s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */