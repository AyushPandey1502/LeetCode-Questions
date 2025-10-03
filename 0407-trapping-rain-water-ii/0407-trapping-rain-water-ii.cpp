class Solution {
public:
    using p = pair<int, pair<int, int>>;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        priority_queue<p, vector<p>, greater<>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = 1;
            }
        }
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = 1;
            }
        }

        int result = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int height = node.first;
            int row = node.second.first;
            int col = node.second.second;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i][0];
                int ncol = col + dir[i][1];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0) {
                    result += max(0, height - heightMap[nrow][ncol]);
                    pq.push({max(height, heightMap[nrow][ncol]), {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return result;
    }
};
