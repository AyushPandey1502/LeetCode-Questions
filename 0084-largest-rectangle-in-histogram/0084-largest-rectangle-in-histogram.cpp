class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if(st.empty() || heights[st.top()] <= heights[i]) st.push(i);
            else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    int right = i;
                    int val = heights[st.top()];
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    result = max(result, (right - left - 1) * val);
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int right = n;
            int val = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            result = max(result, (right - left - 1) * val);

        }
        return result;
    }
};