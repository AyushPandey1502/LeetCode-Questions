class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto [diff, row, col] = pq.top();
            pq.pop();
            if(row == m-1 && col == n-1) return diff;
            for(auto it : dir){
                int nrow = row + it[0], ncol = col + it[1];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, nrow, ncol});
                    }
                }
            }
        }
        return 0;
    }
};