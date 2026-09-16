class MinStack {
public:
    MinStack() {
        
    }
    stack<int> s;
    stack<int> minStack;
    
    void push(int val) {
        if(minStack.empty()) minStack.push(val);
        else minStack.push(min(minStack.top(), val));
        s.push(val);
    }
    
    void pop() {
        minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
