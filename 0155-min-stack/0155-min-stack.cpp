class MinStack {
public:
    stack<long long> st;
    long long minVal;

    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minVal = value;
        } else if (value >= minVal) {
            st.push(value);
        } else {
            st.push(2LL * value - minVal);
            minVal = value;
        }
    }

    void pop() {
        if (st.empty()) return;
        if (st.top() < minVal) {
            minVal = 2LL * minVal - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.empty()) return -1;
        return (st.top() < minVal) ? (int)minVal : (int)st.top();
    }

    int getMin() {
        if (st.empty()) return -1;
        return (int)minVal;
    }
};
