class Solution {
public:
    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<vector<int>> dp(t + 1, vector<int>(26, 0));
        for (int c = 0; c < 26; c++) dp[0][c] = 1;

        for (int i = 1; i <= t; i++) {
            for (int c = 0; c < 26; c++) {
                if (c == 25) dp[i][c] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                else dp[i][c] = dp[i - 1][c + 1];
            }
        }

        int result = 0;
        for (char ch : s) result = (result + dp[t][ch - 'a']) % MOD;
        return result;
    }
};
