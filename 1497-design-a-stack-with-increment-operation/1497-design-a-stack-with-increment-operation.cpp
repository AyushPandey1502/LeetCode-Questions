class CustomStack {
public:
    stack<int> st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() == maxSize) return;
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int val = st.top();
        st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(st.size() != 0){
            if(st.size() <= k){
                int top = st.top();
                st.pop();
                temp.push(top + val);
            }else{
                temp.push(st.top());
                st.pop();
            }
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};
