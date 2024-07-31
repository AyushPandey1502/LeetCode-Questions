class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        int drow[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dcol[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

        while (!pq.empty()) {
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == n - 1) {
                return dis;
            }

            for (int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0) {
                    if (dis + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dis + 1;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};