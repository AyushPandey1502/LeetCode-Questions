class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = heights[0], suffix[n-1] = heights[n-1];
        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i-1], heights[i]); 
        for(int i = n-2; i >= 0; i--) suffix[i] = max(suffix[i+1], heights[i]);
        int result = 0;
        for(int i = 0; i < n; i++){
            result += min(prefix[i], suffix[i]) - heights[i];
        };
        return result;
    }
};