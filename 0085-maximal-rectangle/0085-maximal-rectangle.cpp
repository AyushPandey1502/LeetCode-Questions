class Solution {
public:
    int maxRectArea(vector<int>& nums) {
        nums.push_back(0);
        stack<int> st;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                int ht = nums[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                result = max(result, (i - left - 1) * ht);
            }
            st.push(i);
        }
        nums.pop_back();
        return result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0; 
            }
            result = max(result, maxRectArea(heights));
        }
        return result;
    }
};
