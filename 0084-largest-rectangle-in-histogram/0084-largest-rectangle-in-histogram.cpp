class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n), right(n);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = (st.empty() ? n : st.top());
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
