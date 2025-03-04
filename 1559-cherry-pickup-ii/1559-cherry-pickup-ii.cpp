class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[m-1][i][j] = (i == j ? grid[m-1][i] : grid[m-1][i] + grid[m-1][j]);
            }
        }

        for(int i = m-2; i >= 0; i--){
            for(int j1 = 0; j1 < n; j1++){
                for(int j2 = 0; j2 < n; j2++){
                    int result = -1e8;
                    for(int d1 = -1; d1 <= 1; d1++){
                        for(int d2 = -1; d2 <= 1; d2++){
                            int ncol1 = j1 + d1, ncol2 = j2 + d2;
                            if(ncol1 >= 0 && ncol1 < n && ncol2 >= 0 && ncol2 < n){
                                int val = grid[i][j1];
                                if (j1 != j2) val += grid[i][j2];
                                result = max(result, val + dp[i+1][ncol1][ncol2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = result; 
                }
            }
        }
        return dp[0][0][n-1];
    }
};
