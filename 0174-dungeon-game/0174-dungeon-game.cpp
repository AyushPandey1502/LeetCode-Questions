class Solution {
public:
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        if (i >= m || j >= n) return INT_MAX;
        if (i == m-1 && j == n-1) return max(1, 1 - dungeon[i][j]);
        if (dp[i][j] != -1) return dp[i][j];
        int healthNeeded = min(dfs(i+1, j, dungeon, dp), dfs(i, j+1, dungeon, dp));
        return dp[i][j] = max(1, healthNeeded - dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return dfs(0, 0, dungeon, dp);
    }
};
