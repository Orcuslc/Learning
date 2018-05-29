class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(!s1.empty()) s1.push(x);
        else s2.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!s1.empty()) {
            while(!s1.empty()) {
                int x = s1.top(); s1.pop();
                s2.push(x);
            }
            int x = s2.top(); s2.pop();
            while(!s2.empty()) {
                int y = s2.top(); s2.pop();
                s1.push(y);
            }
            return x;
        }
        else {
            while(!s2.empty()) {
                int x = s2.top(); s2.pop();
                s1.push(x);
            }
            int x = s1.top(); s1.pop();
            while(!s1.empty()) {
                int y = s1.top(); s1.pop();
                s2.push(y);
            }
            return x;
        }
        
    }
    
    /** Get the front element. */
    int peek() {
        if(!s1.empty()) {
            while(!s1.empty()) {
                int x = s1.top(); s1.pop();
                s2.push(x);
            }
            int x = s2.top();
            while(!s2.empty()) {
                int y = s2.top(); s2.pop();
                s1.push(y);
            }
            return x;
        }
        else {
            while(!s2.empty()) {
                int x = s2.top(); s2.pop();
                s1.push(x);
            }
            int x = s1.top();
            while(!s1.empty()) {
                int y = s1.top(); s1.pop();
                s2.push(y);
            }
            return x;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
    
    private:
        stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */