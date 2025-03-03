class Solution {
public:
    int findMinSum(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(findMinSum(i-1, j, dp, grid), findMinSum(i, j-1, dp, grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findMinSum(m-1, n-1, dp, grid);
    }
};