class CustomStack {
public:
    vector<int> st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() == maxSize) return;
        st.push_back(x);
    }
    
    int pop() {
        if(st.size() == 0) return -1;
        int val = st.back();
        st.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int size = min(k, static_cast<int>(st.size()));
        for(int i = 0; i < size; i++){
            st[i] += val;
        }
    }
};
