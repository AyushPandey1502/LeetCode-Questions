class Solution {
   public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> updateMatrix(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1], d = q.front()[2];
            q.pop();
            for (auto it : dir) {
                int nx = x + it.first, ny = y + it.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    dist[nx][ny] = d + 1;
                    q.push({nx, ny, d + 1});
                }
            }
        }
        return dist;
    }
};