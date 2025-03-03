class Solution {
public:
    int countPaths(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        if(row < 0 || col < 0) return 0;
        if(mat[row][col] == 1) return 0; 
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = countPaths(row-1, col, dp, mat) + countPaths(row, col-1, dp, mat);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0; 
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m-1, n-1, dp, obstacleGrid);
    }
};
