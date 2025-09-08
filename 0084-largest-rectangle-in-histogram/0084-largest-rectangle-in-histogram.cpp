class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int result = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                result = max(result, (i - left - 1) * h);
            }
            st.push(i);
        }

        return result;
    }
};
