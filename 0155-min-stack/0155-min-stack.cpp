class MinStack {
public:
    long _min;
    stack <long> s;
    
    MinStack() {}
    
    void push(int val) {
        if(s.empty()) {
            _min = val;
            s.push(val);
        } else if(_min > val) {
            s.push(2l * val - _min);
            _min = val;
        } else s.push(val);
    }
    
    void pop() {
        if(_min >= s.top()) _min = 2l * _min - s.top();
        s.pop();
    }
    
    int top() {
        if(_min <= s.top()) return s.top();
        return _min;
    }
    
    int getMin() {
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */