class Solution {
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if(mat[0][0] == 1) return 0; 
        vector<int> dp(n, 0), temp(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    if(mat[i][j] == 1) temp[j] = 0;
                    else temp[j] = (i > 0 ? dp[j] : 0) + (j > 0 ? temp[j-1] : 0);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};
