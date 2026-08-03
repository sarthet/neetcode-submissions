class MyStack {
    std::queue<int> _data1;
    // 1 2 3 4 5
public:
    MyStack() {
        
    }
    
    void push(int x) {
        _data1.push(x);
    }
    
    int pop() {
        int res = top();
        int size = _data1.size();

        while (size--)
        {
            int value = _data1.front();
            _data1.pop();
            if (size) _data1.push(value);
        }

        return res;
    }
    
    int top() {
        return _data1.size() ? _data1.back() : -1;
    }
    
    bool empty() {
        return _data1.empty();
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