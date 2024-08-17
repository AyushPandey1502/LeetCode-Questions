class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        vector<long long> prev(m, 0);
        for(int j = 0; j < m; j++) {
            prev[j] = points[0][j];
        }
        
        for(int i = 1; i < n; i++) {
            vector<long long> left(m, 0);
            vector<long long> right(m, 0);
            left[0] = prev[0];
            for(int j = 1; j < m; j++) {
                left[j] = max(prev[j], left[j-1] - 1);
            }
            right[m-1] = prev[m-1];
            for(int j = m-2; j >= 0; j--) {
                right[j] = max(prev[j], right[j+1] - 1);
            }
            vector<long long> current(m);
            for(int j = 0; j < m; j++) {
                current[j] = points[i][j] + max(left[j], right[j]);
            }
            prev = current;
        }
        long long result = *max_element(prev.begin(), prev.end());
        return result;
    }
};
