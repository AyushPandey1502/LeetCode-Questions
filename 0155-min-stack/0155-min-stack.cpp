class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top() >= val) minSt.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if(minSt.top() == val) minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};