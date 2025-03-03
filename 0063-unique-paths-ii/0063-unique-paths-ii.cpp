class Solution {
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if(mat[0][0] == 1) return 0; 
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    if(mat[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
