class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string result;
        int row = n, col = m;
        while(row > 0 && col > 0){
            if(str1[row-1] == str2[col-1]){
                result += str1[row-1];
                row--;
                col--;
            }
            else if(dp[row-1][col] > dp[row][col-1]){
                result += str1[row-1];
                row--;
            }
            else{
                result += str2[col-1];
                col--;
            }
        }

        while(row > 0){
            result += str1[row-1];
            row--;
        }
        while(col > 0){
            result += str2[col-1];
            col--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
