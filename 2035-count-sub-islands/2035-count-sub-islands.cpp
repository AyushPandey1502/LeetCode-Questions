class Solution {
public:
    int m;
    int n;
    bool isSubIsland;

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n || grid2[i][j] == 0) return;
        if (grid1[i][j] != grid2[i][j]) {
            isSubIsland = false;
        }
        grid2[i][j] = 0;
        dfs(grid1, grid2, i + 1, j);
        dfs(grid1, grid2, i - 1, j);
        dfs(grid1, grid2, i, j + 1);
        dfs(grid1, grid2, i, j - 1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    isSubIsland = true;
                    dfs(grid1, grid2, i, j);
                    if (isSubIsland) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
