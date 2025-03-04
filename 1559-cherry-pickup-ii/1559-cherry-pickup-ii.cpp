class Solution {
public:
    int m, n;

    int maxCherry(int row, int col1, int col2, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid) {
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) return -1e8;
        if (row == m - 1) {
            if (col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int result = -1e8;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int ncol1 = col1 + d1, ncol2 = col2 + d2;
                if (ncol1 >= 0 && ncol1 < n && ncol2 >= 0 && ncol2 < n) {
                    int val = grid[row][col1];
                    if (col1 != col2) val += grid[row][col2];
                    result = max(result, val + maxCherry(row + 1, ncol1, ncol2, dp, grid));
                }
            }
        }
        return dp[row][col1][col2] = result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return maxCherry(0, 0, n - 1, dp, grid);
    }
};
