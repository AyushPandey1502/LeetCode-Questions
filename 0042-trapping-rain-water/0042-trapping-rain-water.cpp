class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightMax(n);
        rightMax[n-1] = heights[n-1];
        for(int i = n-2; i >= 0; i--) rightMax[i] = max(rightMax[i+1], heights[i]);
        int result = 0, leftMax = 0;
        for(int i = 0; i < n; i++){
            leftMax = max(leftMax, heights[i]);
            result += min(leftMax, rightMax[i]) - heights[i];
        };
        return result;
    }
};