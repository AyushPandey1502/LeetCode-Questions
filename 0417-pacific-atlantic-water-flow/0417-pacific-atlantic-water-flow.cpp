class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited[row][col] = 1;
        for (auto it : dir) {
            int nrow = row + it[0], ncol = col + it[1];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !visited[nrow][ncol] && grid[row][col] <= grid[nrow][ncol]) {
                dfs(nrow, ncol, visited, grid);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)),
                            atlantic(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, heights);
            dfs(m - 1, j, atlantic, heights);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};
