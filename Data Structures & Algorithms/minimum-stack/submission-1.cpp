class MinStack {
private:
    stack<int> m_data;
    stack<int> m_min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // 2 1 1 0
        m_data.push(val);
        if (m_min_stack.size() != 0)
        {
            val = std::min(m_min_stack.top(), val);
        }
        m_min_stack.push(val);
    }
    
    void pop() {
        m_min_stack.pop();
        m_data.pop();
    }
    
    int top() const {
        return m_data.top();
    }
    
    int getMin() const {
        return m_min_stack.top();
    }
};
