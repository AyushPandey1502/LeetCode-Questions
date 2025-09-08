class Solution {
   public:
    vector<int> findPSE(vector<int>& nums, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> findNSE(vector<int>& nums, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = findNSE(heights, n);
        vector<int> pse = findPSE(heights, n);

        int result = 0;
        for (int i = 0; i < n; i++) {
            int area = (nse[i] - pse[i] - 1) * heights[i];
            result = max(result, area);
        }
        return result;
    }
};