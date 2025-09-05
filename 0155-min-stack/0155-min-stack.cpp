class MinStack {
public:
    stack<int> st, minSt;

    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) minSt.push(x);
    }

    void pop() {
        if (st.empty()) return;
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return st.empty() ? -1 : st.top();
    }

    int getMin() {
        return minSt.empty() ? -1 : minSt.top();
    }
};
