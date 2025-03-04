class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < m; i++){
            for(int j = 0; j <= i; j++){
                int up = (j < i ? dp[i-1][j] : 1e9);
                int leftDiag = (j > 0 ? dp[i-1][j-1] : 1e9);
                dp[i][j] = triangle[i][j] + min(up, leftDiag);
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};