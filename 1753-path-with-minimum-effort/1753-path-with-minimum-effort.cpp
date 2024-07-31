class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        int drow[4] = {0, 0, 1, -1};
        int dcol[4] = {-1, 1, 0, 0};

        while (!pq.empty()) {
            int eff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n-1 && col == m-1) {
                return eff;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEff = max(eff, abs(heights[row][col] - heights[nrow][ncol]));
                    if (newEff < efforts[nrow][ncol]) {
                        efforts[nrow][ncol] = newEff;
                        pq.push({newEff, {nrow, ncol}});
                    }
                }
            }
        }

        return 0; 
    }
};